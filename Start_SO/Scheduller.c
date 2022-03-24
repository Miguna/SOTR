/*
 * 
 * Inclusion de librerias
 * 
 */
#include "AppTypes.h"
#include "Scheduller.h"
#include "RTOS.h"
extern T_TCB IdleTaskHandler;
T_QUEUE_HANDLER ReadyTaskList[RTOS_SYSTEM_PRIORITIES];

uint_16 Scheduller_Init(vi){
	uint_16 Res = SCHEDULLER_OK;
	uint_16 Count;
	for(Count = 0;Count < RTOS_SYSTEM_PRIORITIES; Count++){
		Res = Queue_Init(&ReadyTaskList[Count]);
		if(Res != QUEUE_OK){
			break;
		}
	}
	return Res;
}
uint_16 Scheduller_Coperative(uint_16 ActualTaskSP){
    uint_16 Res;
    uint_16 Count;
    T_TCB_PTR Task =NULL;
    T_QUEUE_ELEMENT_PTR Element = NULL;
    Task = Task_Get_ActualTask();
    if(Task != NULL){
    	if	(ActualTaskSP != 0){
    		Task ->TaskActualStack = ActualTaskSP;
    	}
        if(Task != &IdleTaskHandler){
			if(Task->Status == RUNNING){ //si la tarea est� en running	
				Res = Scheduller_SetTaskToReadyQueue(Task);//Se pone la tarea que ya esta lista para ejecutarse
				}
        }
        else{
        	Task->Status = READY;
        }
    }
    Task = NULL;//se borra el apuntador de tarea

    for (Count = 0; Count < RTOS_SYSTEM_PRIORITIES; Count++)
    {//se recorre para ver si hay tareas listas para ejecutar
        if(Queue_GetCount(&ReadyTaskList[Count])>0){
            //se saca, se manda el handler de la cola donde se quiere desencolar
            Res = Queue_Dequeue(&ReadyTaskList[Count], &Element);
            if(Res == QUEUE_OK){
                if(Element != NULL){//SI LOGR� DESENCOLAR, EL APUNTADOR DE ELEMENTO SERA DIFERENTE A NULO 
                    Task = Element -> Data;//saca el TCB de la tarea y rompe el ciclo
                    break;
                	} 
            	}
        	}
    	}
    
    if(Task == NULL){
        
    	Task = &IdleTaskHandler; 
    }
    Task -> Status = RUNNING; //pasa a estado de ejecuci�n
    Task_SetActualTask(Task);
    //se debe encontrar el stackpointer
    return Task->TaskActualStack;
    
}