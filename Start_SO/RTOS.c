#include "AppTypes.h"
#include "Scheduller.h"
#include "RTOS.h"
#include "Task.h"

T_TCB   	IdleTaskHandler;
uint_8		IdleTaskStack[RTOS_IDLE_TASK_STACK_SIZE];

vi IdleTask(pvi Param){for(;;){}}
uint_16 RTOS_Init(vi){return Scheduller_Init();}
uint_16 RTOS_Start(vi){
	uint_16	Res;
	uint_16	FirstTaskSP;
	Res = Task_Create(&IdleTaskHandler, RTOS_IDLE_TASK_ID, RTOS_IDLE_TASK_NAME, RTOS_IDLE_TASK_PRIORITY, IdleTaskStack, RTOS_IDLE_TASK_STACK_SIZE, IdleTask, NULL);
	if(Res){
		return Res;
	}
	IdleTaskHandler.TaskPriority = RTOS_IDLE_TASK_PRIORITY;
	FirstTaskSP = Scheduller_Coperative(0);
	Portable_InitTickRTC();
	Portable_RestoreManualContext(FirstTaskSP);
	return Res;	
}
