#include "Task.h"
#include "AppTypes.h"
#include "RTOS.h"
#include "Portable.h"

#define TIMEROFF16 500


T_TCB_PTR ActualTask = NULL; 

T_TCB_PTR Task_GetActualTask(void){return ActualTask;}
vi Task_SetActualTask(T_TCB_PTR Task){ActualTask = Task;}

uint_16 Task_Create(T_TCB_PTR TaskHandler,uint_16 Id, pint_8 Name, uint_8 Priority, pint_8 Stack, uint_16 StackSize, TaskFunction Function, void * Param ){
	uint_16 Res = TASK_ERROR_NULL_PARAM;
	if((TaskHandler != NULL) && (Function != NULL) && (Stack != NULL ) && (StackSize > 0)){// Chekea que exista en memoria los parametros recibidos (apuntadores)
		Res = TASK_ERROR_PARAM_OUT_OF_RANGE;
		if(StackSize >= RTOS_MIN_STACK_SIZE	){ // El tamaño de stack debe ser mayor que el minimo permitido
			Res = TASK_OK;
			if(Priority > RTOS_MIN_PRIORITY){ // Si la prioridad es mayor (en valor entero) que la minima, le asigna la minima
				Priority = RTOS_MIN_PRIORITY;  
			}
			//revisar para aplicar cambios
			TaskHandler -> Id = Id;
			TaskHandler -> TaskName = Name;
			TaskHandler -> TaskPriority = Priority;
			TaskHandler -> TaskParam = Param;
			TaskHandler -> TaskCallback = Function;
			TaskHandler -> TaskStack = Stack;
			TaskHandler -> TaskStackSize = StackSize; 
			TaskHandler -> TaskSleepTime = TIMEROFF16;
			TaskHandler -> TaskActualTask = (uint_16)Portable_InitTaskContext(&Stack[StackSize],Function, Param);
			// Asigna los valores al contexto de la tarea, iniciando desde la ultima posicion del stack.
			Res = Scheduller_SetTaskToReadyQueue(TaskHandler); // El elemento de cola es un puntero a TCB y lo encola en la cola de prioridad
		}
	}
	return Res;
}
