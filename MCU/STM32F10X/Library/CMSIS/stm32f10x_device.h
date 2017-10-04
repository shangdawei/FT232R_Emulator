#ifndef __STM32F10X_DEVICE_H__
#define __STM32F10X_DEVICE_H__

#if defined ( STM32F100C4 ) || defined ( STM32F100C6 )
#define STM32F10X_LD_VL
#elif defined ( STM32F100C8 ) || defined ( STM32F100CB )
#define STM32F10X_MD_VL
#elif defined ( STM32F100R4 ) || defined ( STM32F100R6 )
#define STM32F10X_LD_VL
#elif defined ( STM32F100R8 ) || defined ( STM32F100RB )
#define STM32F10X_MD_VL
#elif defined ( STM32F100RC ) || defined ( STM32F100RD ) || defined ( STM32F100RE )
#define STM32F10X_HD_VL
#elif defined ( STM32F100V8 ) || defined ( STM32F100VB )
#define STM32F10X_MD_VL
#elif defined ( STM32F100VC ) || defined ( STM32F100VD ) || defined ( STM32F100VE )
#define STM32F10X_HD_VL
#elif defined ( STM32F100ZC ) || defined ( STM32F100ZD ) || defined ( STM32F100ZE )
#define STM32F10X_HD_VL

#elif defined ( STM32F101C4 ) || defined ( STM32F101C6 )
#define STM32F10X_LD
#elif defined ( STM32F101C8 ) || defined ( STM32F101CB )
#define STM32F10X_MD
#elif defined ( STM32F101R4 ) || defined ( STM32F101R6 )
#define STM32F10X_LD
#elif defined ( STM32F101R8 ) || defined ( STM32F101RB )
#define STM32F10X_MD
#elif defined ( STM32F101RC ) || defined ( STM32F101RD ) || defined ( STM32F101RE )
#define STM32F10X_HD
#elif defined ( STM32F101RF ) || defined ( STM32F101RG )
#define STM32F10X_XL
#elif defined ( STM32F101T4 ) || defined ( STM32F101T6 )
#define STM32F10X_LD
#elif defined ( STM32F101T8 ) || defined ( STM32F101TB )
#define STM32F10X_MD
#elif defined ( STM32F101V8 ) || defined ( STM32F101VB )
#define STM32F10X_MD
#elif defined ( STM32F101VC ) || defined ( STM32F101VD ) || defined ( STM32F101VE )
#define STM32F10X_HD
#elif defined ( STM32F101VF ) || defined ( STM32F101VG )
#define STM32F10X_XL
#elif defined ( STM32F101ZC ) || defined ( STM32F101ZD ) || defined ( STM32F101ZE )
#define STM32F10X_HD
#elif defined ( STM32F101ZF ) || defined ( STM32F101ZG )
#define STM32F10X_XL

#elif defined ( STM32F102C4 ) || defined ( STM32F102C6 )
#define STM32F10X_LD
#elif defined ( STM32F102C8 ) || defined ( STM32F102CB )
#define STM32F10X_MD
#elif defined ( STM32F102R4 ) || defined ( STM32F102R6 )
#define STM32F10X_LD
#elif defined ( STM32F102R8 ) || defined ( STM32F102RB )
#define STM32F10X_MD

#elif defined ( STM32F103C4 ) || defined ( STM32F103C6 )
#define STM32F10X_LD
#elif defined ( STM32F103C8 ) || defined ( STM32F103CB )
#define STM32F10X_MD
#elif defined ( STM32F103R4 ) || defined ( STM32F103R6 )
#define STM32F10X_LD
#elif defined ( STM32F103R8 ) || defined ( STM32F103RB )
#define STM32F10X_MD
#elif defined ( STM32F103RC ) || defined ( STM32F103RD ) || defined ( STM32F103RE )
#define STM32F10X_HD
#elif defined ( STM32F103RF ) || defined ( STM32F103RG )
#define STM32F10X_XL
#elif defined ( STM32F103T4 ) || defined ( STM32F103T6 )
#define STM32F10X_LD
#elif defined ( STM32F103T8 ) || defined ( STM32F103TB )
#define STM32F10X_MD
#elif defined ( STM32F103V8 ) || defined ( STM32F103VB )
#define STM32F10X_MD
#elif defined ( STM32F103VC ) || defined ( STM32F103VD ) || defined ( STM32F103VE )
#define STM32F10X_HD
#elif defined ( STM32F103VF ) || defined ( STM32F103VG )
#define STM32F10X_XL
#elif defined ( STM32F103ZC ) || defined ( STM32F103ZD ) || defined ( STM32F103ZE )
#define STM32F10X_HD
#elif defined ( STM32F103ZF ) || defined ( STM32F103ZG )
#define STM32F10X_XL

#elif defined ( STM32F105R8 ) || defined ( STM32F105RB ) || defined ( STM32F105RC ) 
#define STM32F10X_CL
#elif defined ( STM32F105V8 ) || defined ( STM32F105VB ) || defined ( STM32F105VC ) 
#define STM32F10X_CL

#elif defined ( STM32F107R8 ) || defined ( STM32F107RB ) || defined ( STM32F107RC ) 
#define STM32F10X_CL
#elif defined ( STM32F107V8 ) || defined ( STM32F107VB ) || defined ( STM32F107VC ) 
#define STM32F10X_CL

#else
#error Please select the target STM32F10XXX device used in your project.
#endif

#endif /* __STM32F10X_DEVICE_H__ */
