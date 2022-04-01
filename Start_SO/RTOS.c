#include "AppTypes.h"
#include "Scheduller.h"
#include "RTOS.h"
#include "Task.h"

T_TCB   	IdleTaskHandler;
int_8		IdleTaskStack[RTOS_IDLE_TASK_STACK_SIZE];

vi IdleTask(pvi Param){for(;;){}}
uint_16 RTOS_Init(vi){return Scheduller_Init();}
uint_16 RTOS_Start(vi){
	uint_16	Res;
	uint_16	FirstTaskSP;
	Res = Task_Create(&IdleTaskHandler, RTOS_IDLE_TASK_ID,(pint_8) RTOS_IDLE_TASK_NAME, RTOS_IDLE_TASK_PRIORITY, (pint_8)IdleTaskStack, RTOS_IDLE_TASK_STACK_SIZE, IdleTask, NULL);
	if(Res){
		return Res;
	}
	IdleTaskHandler.TaskPriority = RTOS_IDLE_TASK_PRIORITY; // Le devuelve la prioridad 8 que tiene como idle task
	//-----Hasta aca ya esta creada la tarea inactiva.
	FirstTaskSP = Scheduller_Coperative((uint_16) 0); // Inicie el modo cooperativo, devuelve el actual stack
	(void) Portable_InitTickRTC();
	(void) Portable_RestoreManualContext(FirstTaskSP);
	return Res;	
}
