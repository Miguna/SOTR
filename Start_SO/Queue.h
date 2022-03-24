#ifndef __QUEUE_H__  // verifica si esta la variable definida (solo estara definida si ya paso por el archivo)

#define __QUEUE_H__  // Solo lo compila una vez
#define QUEUE_OK                0
#define QUEUE_BASE_ERR          0x0500
#define QUEUE_ERR_NULL          QUEUE_BASE_ERR|0x00FF
#define QUEUE_ERR_OUT_OF_RANGE  0x0600

#include "AppTypes.h"

typedef struct Queue_element{
    pvi Data;
    struct Queue_element * Netx;
} T_QUEUE_ELEMENT, * T_QUEUE_ELEMENT_PTR;

typedef struct {
    uint_16 count;
    T_QUEUE_ELEMENT_PTR Head;
    T_QUEUE_ELEMENT_PTR Tail;
} T_QUEUE_HANDLER, * T_QUEUE_HANDLER_PTR;

uint_16 Queue_Init(T_QUEUE_HANDLER_PTR Queue);
uint_16 Queue_GetCount(T_QUEUE_HANDLER_PTR Queue);
uint_16 Queue_Enqueue(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR Element);
uint_16 Queue_Dequeue(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR * Element);

#endif

// "Yo paso la direccion del contenicdo que quiero modifcar"
// "Retorne un codigo numerico (retorne un codigo de error) de la funcion para saber si se ejecuto correctamente o no"
// "Se puede manejar una deficnion de manejo de codigos de errores."