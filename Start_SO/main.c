/*#include	"Cpu.h"
#include	"Events.h"
#include	"PE_Types.h"
#include	"PE_Error.h"
#include	"PE_Const.h"
#include	"IO_Map.h"*/
#include 	"RTOS.h"
#include "AppTypes.h"



T_TCB 	Tarea1;
u8		Tarea1Stack[RTOS_MIN_STACK_SIZE];

T_TCB 	Tarea2;
u8		Tarea2Stack[RTOS_MIN_STACK_SIZE];


void main(void){
	PE_low_level_init();
	
	RTOS_Init();
	Task_Create(&Tarea1, 1,"Tarea 1", 5, Tarea1Stack, RTOS_MIN_STACK_SIZE,FuncionTarea1,500);
	Task_Create(&Tarea2, 2,"Tarea 2", 6, Tarea2Stack, RTOS_MIN_STACK_SIZE,FuncionTarea1,1000);
	
	RTOS_Start();
	
	
	#ifdef	PEX_RTOS_START
		PEX_RTOS_START();
	#endif
	
	
	
	
	for(;;){} 
}



void FuncionTarea1(void * Param)
{
	u16 Time = (u16)Param;
	u16 Count;
		for(;;){
			for(Count = Time; Count > 0; Count ++)
			{}
			Led1_NegVal();
		}
}
