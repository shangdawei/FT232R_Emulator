#include "List.h"

static LIST * LIST_Init( LIST * List )
{
  List->prev = List;
  List->next = List;
  return List;
}

/*
 * before_list <---> List <---> after_list
 * before_list <--------------> after_list
 */
static void LIST_Delete( LIST * List )
{
  List->prev->next = List->next;
  List->next->prev = List->prev;
  LIST_Init( List );
}

/*
 * before_where <---> Where <---> after_where
 * before_where <---> Where <---> List <---> after_list
 *
 */
static void LIST_InsertAfter( LIST * Where, LIST * List )
{
  List->next = Where->next;
  List->prev = Where;

  Where->next->prev = List;
  Where->next = List;
}

/*
 * before_where <---> Where <---> after_where
 * before_list  <---> List  <---> Where <---> after_where
 *
 */
static void LIST_InsertBefore( LIST * Where, LIST * List )
{
  List->next = Where;
  List->prev = Where->prev;

  Where->prev->next = List;
  Where->prev = List;
}

void LIST_InitHead( LIST_HEAD * Head )
{
  Head->count = 0;
  Head->first = 0;
}

/*
 * Head ---> First <---> last
 * Head ---> List <---> First <---> last
 */
void LIST_Insert( LIST_HEAD * Head, void * List )
{
  if ( Head->first == 0 )
    Head->first = (LIST *) List;

  LIST_InsertBefore( Head->first, (LIST *) List );

  Head->count++;
}

/*
 * Head ---> First <---> last
 * Head ---> First <---> last <---> List
 */
void LIST_Append( LIST_HEAD * Head, void * List )
{
  if ( Head->first == 0 ) // Append it as First
    Head->first = (LIST *) List;

  LIST_InsertAfter( Head->first->prev, (LIST *) List );

  Head->count++;
}

void LIST_Remove( LIST_HEAD * Head, void * List )
{
  if ( Head->count > 0 )
  {
    if ( Head->first == (LIST *) List ) // Remove First
      Head->first = ( (LIST *) List )->next;

    LIST_Delete( (LIST *) List );

    Head->count--;
    if ( Head->count == 0 )
      Head->first = 0;
  }
}

void * LIST_Query( LIST_HEAD * Head, LIST_QUERY_CB * LIST_QueryCb,
  void * Context )
{
  LIST * List = Head->first;
  for ( uint32_t i = 0; i < Head->count; i++ )
  {
    if ( LIST_QueryCb( List, Context ) )
    {
      Head->first = List;
      return List;
    }

    List = List->next;
  }
  return 0;
}

void LIST_RemoveAll( LIST_HEAD * Head )
{
  while ( Head->first )
    LIST_Remove( Head, Head->first );
}

void * LIST_GetFirst( LIST_HEAD * Head )
{
  return Head->first;
}

void * LIST_GetNext( void * current )
{
  return ( (LIST *) current )->next;
}

uint32_t LIST_GetCount( LIST_HEAD * Head )
{
  return Head->count;
}

/*******************************************************************************
 * Demo
 */

LIST_NODE_HEAD( NODE )
  uint32_t a;
LIST_NODE_TAIL()

#define NODE_COUNT ( 4 )

static uint32_t QueryDeviceCb( NODE * List, void * a )
{
  return ( List->a == (uint32_t) a );
}

void LIST_Demo( void )
{
  uint32_t a = 2;

  NODE * List;
  NODE Nodes[ NODE_COUNT ];

  LIST_HEAD node_head;
  LIST_InitHead( &node_head );

  for ( uint32_t i = 0; i < 4; i++ )
  {
    Nodes[ i ].a = i;
    LIST_Insert( &node_head, &Nodes[ i ] );
    List = LIST_Query( &node_head, (LIST_QUERY_CB *) &QueryDeviceCb,
      (void*) a );
    if ( List )
      List->a = 0;
  }

  for ( uint32_t i = 0; i < 4; i++ )
    LIST_Remove( &node_head, &Nodes[ i ] );
}
