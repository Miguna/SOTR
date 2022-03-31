#include "Queue.h"
#include "AppTypes.h"

uint_16 Queue_Init(T_QUEUE_HANDLER_PTR Queue){
    uint_16 Res=QUEUE_ERR_NULL;
    if(Queue){
        Queue->count=0;
        Queue->Head=NULL;
        Queue->Tail=NULL;
        Res=QUEUE_OK;
    }
    return Res;
}

uint_16 Queue_GetCount(T_QUEUE_HANDLER_PTR Queue){
    if(Queue){
    	return Queue->count;
    }
    return 0;
}
uint_16 Queue_Enqueue(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR Element){
    uint_16 Res=QUEUE_ERR_NULL;
    //uint_16 Res = Queue_ERROR_NULL_PARAM;
	//Portable_DisableInterrupts();
    if ((Queue) && (Element)){
        Queue->count++;
        Element->Netx=NULL;
        if(Queue->Tail){
            Queue->count++;
        }
        else{
            Queue->Head=Element;
            Queue->count=1;
        }
        Queue->Tail=Element;
        Res=QUEUE_OK;
    }
    //Portable_EnableInterrupts();
    return Res;
}
uint_16 Queue_Dequeue(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR * Element){
    uint_16 Res=QUEUE_ERR_NULL;
    if ((Queue) && (Element)){ //Verifica que los apuntadores no sean nulos
        if (Queue->Head){
            *Element = Queue->Head;
            Queue->count--;
            if(Queue->Head==Queue->Tail){
                Queue->Head=NULL;
                Queue->Tail=NULL;
            }else{
                Queue->Head=Queue->Head->Netx;
            }
            Res=QUEUE_OK;
        }
    }
    return Res;
}
//siempre hay que verificar si el apuntador no es nulo, si se trabaja con apuntadores
