#ifndef __APP_TYPES_H__  // verifica si esta la variable definida (solo estara definida si ya paso por el archivo)
#define __APP_TYPES_H__  // Solo lo compila una vez

#ifndef NULL
#define NULL ((void*) 0)
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

#define MAIN_BASE_ERROR					0x0100
#define QUEUE_BASE_ERROR				0x0200
#define RTOS_BASE_ERROR					0x0300
#define SCHEDULLER_BASE_ERROR			0x0400
#define TASK_BASE_ERROR					0x0500
#define SEMAPHORE_BASE_ERROR			0x0600
#define MUTEX_BASE_ERROR				0x0700
#define EVENT_BASE_ERROR				0x0800

#define	BASE_ERROR_UNKNOW				0x00FF
#define	BASE_ERROR_NULL_PARAM			0x00FE
#define	BASE_ERROR_EMPTY				0x00FD
#define BASE_ERROR_PARAM_OUT_OF_RANGE	0x00FC

#endif