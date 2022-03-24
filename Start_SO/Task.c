#include "task.h"
#include "AppTypes.h"
#include "RTOS.h"
#include "Portable.h"


T_TCB_PTR ActualTask = NULL; 

T_TCB_PTR Task_GetActualTask(void){return ActualTask;}
vi Task_SetActualTask(T_TCB_PTR Task){ActualTask = Task;}

uint_16 Task_Create(T_TCB_PTR TaskHandler,uint_16 Id, char * Name, uint_8 Priority, puint_8 Stack, uint_16 StackSize, TaskFunction Function, void * Param ){
	uint_16 Res = TASK_ERROR_NULL_PARAM;
	if((TaskHandler != NULL) && (Function != NULL) && (Stack != NULL ) && (StackSize > 0))
	{
		Res = TASK_ERROR_PARAM_OUT_OF_RANGE;
		if(StackSize >= RTOS_MIN_STACK_SIZE	){
			
			Res = TASK_OK;
			if(Priority > RTOS_MIN_PRIORITY){
				
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
			Res = Scheduller_SetTaskToReadyQueue(TaskHandler);
		}
	}
	return Res;