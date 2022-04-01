/*
 * 
 * Inclusion de librerias
 * 
 */
#include "AppTypes.h"
#include "Scheduller.h"
#include "RTOS.h"
#include "Task.h"

extern T_TCB IdleTaskHandler;
T_QUEUE_HANDLER ReadyTaskList[RTOS_SYSTEM_PRIORITIES];

uint_16 Scheduller_Init(vi){
	uint_16 Res = SCHEDULLER_OK;
	uint_16 Count;
	for(Count = 0;Count < RTOS_SYSTEM_PRIORITIES; Count++){ // Define que solo va a recorrer las prioridades ([0,1,2,3,4,5,6,7])
		Res = Queue_Init(&ReadyTaskList[Count]);// Creando una cola (espacio de memoria), para cada prioridad
		if(Res != QUEUE_OK){ //Recordad que queue Init puede devolver error. 
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
    Task = Task_GetActualTask(); // Si no ha sido modificado con un Task_SetActualTask devuelve NULO// Solo se modifica en la linea 37 de este archivo
    if(Task != NULL){
    	if	(ActualTaskSP != 0){
    		Task ->TaskActualStack = ActualTaskSP;
    	}
        if(Task != &IdleTaskHandler){// Si la tarea no es la inactiva
			if(Task->Status == RUNNING){ //Ponga la tarea a correr 	
				Res = Scheduller_SetTaskToReadyQueue(Task); //Se pone la tarea en la cola que ya esta lista para ejecutarse
				}
        }
        else{// Si la tarea es la inactiva
        	Task->Status = READY;
        }
    }
    Task = NULL;//se borra el apuntador de tarea

    for (Count = 0; Count < RTOS_SYSTEM_PRIORITIES; Count++){//se recorre para ver si hay tareas listas para ejecutar
        if(Queue_GetCount(&ReadyTaskList[Count]) > 0){// Si hay un elemento en la cola de prioridad es decir una tarea.
            Res = Queue_Dequeue(&ReadyTaskList[Count], &Element); //se saca  el puntero a TCB de la cola de prioridad
            if(Res == QUEUE_OK){ // Desencolo bien?
                if(Element != NULL){//El que desencolo es no nulo? 
                    Task = Element -> Data;// Saca el puntero del TCB y lo asigna como tarea
                    break;
                	} 
            	}
        	}
    	}
    if(Task == NULL){ // Si el Task que saco de la cola es Nulo, asignele la direccion de la tarea inactiva
    	Task = &IdleTaskHandler; 
    }
    Task -> Status = RUNNING; //pasa la tarea que desencolo a estado de ejecucion
    Task_SetActualTask(Task); // Y la pone como tarea actual
    return Task->TaskActualStack;
}
uint_16 Scheduller_SetTaskToReadyQueue(T_TCB_PTR Task){
	uint_16 Res=TASK_ERROR_NULL_PARAM;
	if(Task){// Si no es nulo entre
		if(Task->TaskPriority < RTOS_SYSTEM_PRIORITIES){ // Si no es la tarea inactiva
			Task->Status = READY; // Ponga la tarea Como lista
			(void)Queue_Enqueue(&ReadyTaskList[Task->TaskPriority],&Task->TaskQueueElement); // Busco la cola correspondiente a la prioridad
			// y agrego a esa cola la tarea actual respectiva 
		}
		Res=TASK_OK;
	}
	return Res;
}
