#ifndef __APP_TYPES_H__  // verifica si esta la variable definida (solo estara definida si ya paso por el archivo)
#define __APP_TYPES_H__  // Solo lo compila una vez

#ifndef NULL
#define NULL((void*) 0)
#endif

typedef signed char       int_8;
typedef unsigned char     uint_8;
typedef signed char *     pint_8;
typedef unsigned char *   puint_8;
typedef signed short      int_16;
typedef unsigned short    uint_16;
typedef signed short *    pint_16;
typedef unsigned short *  puint_16;
typedef signed long       int_32;
typedef unsigned long     uint_32;
typedef signed long *     pint_32;
typedef unsigned long *   puint_32;
typedef signed long long      int_64;
typedef unsigned long long    uint_64;
typedef signed long long *    pint_64;
typedef unsigned long long *  puint_64;
typedef float     real_32;
typedef float *   preal_32;
typedef double    real_64;
typedef double *  preal_64;
typedef void      vi,* pvi;

#endif