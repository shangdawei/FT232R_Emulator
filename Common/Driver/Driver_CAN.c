#include "Driver_CAN.h"

#define CAN_CALC_MAX_ERROR 50   // in one-tenth of a percent

int32_t CAN_UpdateSamplePoint( CAN_BitTimingConst_TypeDef *btc,
  int32_t sampl_pt, int32_t tseg, int32_t *tseg1, int32_t *tseg2 )
{
  *tseg2 = tseg + 1 - ( sampl_pt * ( tseg + 1 ) ) / 1000;

  if ( *tseg2 < btc->tseg2_min )
    *tseg2 = btc->tseg2_min;

  if ( *tseg2 > btc->tseg2_max )
    *tseg2 = btc->tseg2_max;

  *tseg1 = tseg - *tseg2;

  if ( *tseg1 > btc->tseg1_max )
  {
    *tseg1 = btc->tseg1_max;
    *tseg2 = tseg - *tseg1;
  }

  return 1000 * ( tseg + 1 - *tseg2 ) / ( tseg + 1 );
}

// CIA Sample Point : 75.0% : Speed > 800000
// CIA Sample Point : 80.0% : Speed > 500000
// CIA Sample Point : 87.5% : Speed <= 500000
uint32_t CAN_CIA_SamplePoint( uint32_t bitrate )
{
  uint32_t sampl_pt;

  if ( bitrate > 800000 )
    sampl_pt = 750;
  else if ( bitrate > 500000 )
    sampl_pt = 800;
  else
    sampl_pt = 875;

  return sampl_pt;
}

int32_t CAN_CalcBitTiming( CAN_BitTimingConst_TypeDef *btc,
  CAN_BitTiming_TypeDef *bt )
{
  uint64_t v64;
  int32_t rate = 0;
  int32_t best_error = 1000000000, error = 0;
  int32_t best_tseg = 0, best_brp = 0, brp = 0;
  int32_t tsegall, tseg = 0, tseg1 = 0, tseg2 = 0;
  int32_t spt_error = 1000, spt = 0, sampl_pt;

  // Use gived sample points
  if ( bt->sample_point )
    sampl_pt = bt->sample_point;
  else
    // Use CIA recommended sample points
    sampl_pt = CAN_CIA_SamplePoint( bt->bitrate );

  // tseg even = round down, odd = round up
  for ( tseg = ( btc->tseg1_max + btc->tseg2_max ) * 2 + 1;
      tseg >= ( btc->tseg1_min + btc->tseg2_min ) * 2; tseg-- )
  {
    tsegall = 1 + tseg / 2;

    // Compute all possible tseg choices (tseg=tseg1+tseg2)
    brp = bt->ref_clk / ( tsegall * bt->bitrate ) + tseg % 2;

    // chose brp step which is possible in system
    brp = ( brp / btc->brp_inc ) * btc->brp_inc;
    if ( ( brp < btc->brp_min ) || ( brp > btc->brp_max ) )
      continue;

    rate = bt->ref_clk / ( brp * tsegall );
    error = bt->bitrate - rate;

    // tseg brp biterror
    if ( error < 0 )
      error = -error;

    if ( error > best_error )
      continue;

    best_error = error;
    if ( error == 0 )
    {
      spt = CAN_UpdateSamplePoint( btc, sampl_pt, tseg / 2, &tseg1, &tseg2 );
      error = sampl_pt - spt;
      if ( error < 0 )
        error = -error;
      if ( error > spt_error )
        continue;

      spt_error = error;
    }

    best_tseg = tseg / 2;
    best_brp = brp;
    if ( error == 0 )
      break;
  }

  if ( best_error )
  {
    /* Error in one-tenth of a percent */
    error = ( best_error * 1000 ) / bt->bitrate;
    if ( error > CAN_CALC_MAX_ERROR )
    {
      // error ( "bitrate error %ld.%ld%% too high\n", error / 10, error % 10 );
      return DRIVER_ERROR_PARAMETER;
    }
    else
    {
      // warn( "bitrate error %ld.%ld%%\n", error / 10,  error % 10 );
    }
  }

  v64 = ( (uint64_t) best_brp * 1000000000UL ) / bt->ref_clk;

  bt->tq = (uint32_t) v64;
  bt->brp = best_brp;
  bt->tseg2 = tseg2;
  bt->tseg1 = tseg1;
  bt->sjw = 1;
  // bt->prop_seg = tseg1 / 2;
  // bt->phase_seg1 = tseg1 - bt->prop_seg;
  // bt->phase_seg2 = tseg2;

  // real bit-rate
  bt->bitrate = bt->ref_clk / ( bt->brp * ( tseg1 + tseg2 + 1 ) );
  // real sample point

  bt->sample_point = CAN_UpdateSamplePoint( btc, sampl_pt, best_tseg, &tseg1,
    &tseg2 );

  return DRIVER_OK;
}

