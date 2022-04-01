/*#include	"Cpu.h"

#include	"Events.h"
#include "Tick.h"
#include	"PE_Types.h"
#include	"PE_Error.h"
#include	"PE_Const.h"
#include "IO_Map.h"
#include	"IO_Map.h"*/
#include    "Cpu.h"
#include 	"RTOS.h"
#include    "AppTypes.h"

void FuncionTarea1(void * Param);

T_TCB 	Tarea1;
int_8		Tarea1Stack[RTOS_MIN_STACK_SIZE];

T_TCB 	Tarea2;
int_8		Tarea2Stack[RTOS_MIN_STACK_SIZE];


void main(void){
	PE_low_level_init();
	
	(vi)RTOS_Init();
	
	(vi)Task_Create(&Tarea1, 1, (pint_8) "Tarea 1", 5, (pint_8)Tarea1Stack, RTOS_MIN_STACK_SIZE, FuncionTarea1,(void *) 500);
	(vi)Task_Create(&Tarea2, 2, (pint_8) "Tarea 2", 6, (pint_8)Tarea2Stack, RTOS_MIN_STACK_SIZE, FuncionTarea1,(void *) 1000);
	
	(void)RTOS_Start();

	#ifdef	PEX_RTOS_START
		PEX_RTOS_START();
	#endif

	for(;;){} 
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
void FuncionTarea1(void * Param){
	uint_16 Time = (uint_16)Param;
	uint_16 Count;
		for(;;){
			for(Count = Time; Count > 0; Count ++)
			{}
			//Led1_NegVal();
		}
}
