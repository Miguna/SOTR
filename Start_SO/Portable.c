#include "AppTypes.h"
#include "Portable.h"
#include "IO_Map.h"

/*
 * 
 * Definicion de variables globales internas del m�dulo
 * 
 */

extern 	uint_16 RTOS_Scheduller(uint_16 ActualStack);
/*extern	v	RTOS_DecrementTimers(vi);*/


uint_16 CurrentStackPtr;// asi se almacena HX
uint_8  CriticalNesting = 0;


puint_8 Portable_InitTaskContext (puint_8 Stack, TaskFunction Function, pvi Param) 
{
	if((!Stack)||(!Function))
	{
		return NULL;
	}
	Stack--;
	*Stack = (uint_8)((uint_16)Function & 0x00FF);		//Asignacion PC Low
	Stack--;
	*Stack = (uint_8)(((uint_16)Function >> 8)& 0x00FF);//Asignacion PC High
	Stack--;
	*Stack=	 (uint_8)((uint_16)Param & 0x00FF);;	//Asignacion X
	Stack--;
	*Stack=0;	//Asignacion del A(acumulador)
	Stack--;
	*Stack=0;	//Asignacion de CCR (codigo de condicion)
	Stack--;
	*Stack=  (uint_8)(((uint_16)Param >> 8)& 0x00FF);	//Asignacion de H
	Stack--;
	*Stack=0;	//Asignacion del Critical Nesting
	return Stack;
}

 

vi Portable_RestoreManualContext(uint_16 Stack){
	
	CurrentStackPtr = Stack;
	asm{
		LDHX	CurrentStackPtr
		TXS	
		PULA
		STA		CriticalNesting
		PULH
		RTI
	}
}

vi Portable_InitTickRTC(vi){
	RTC_SC2 = 0x00;
	RTC_MOD = 0x01;
	RTC_MOD = RTC_MOD;
	RTC_SC2 = 0x98;
}

vi Portable_DisableInterrupts(vi){
	asm(SEI);
	CriticalNesting++;
}

vi Portable_EnableInterrupts(vi){
	
	if(CriticalNesting){
		CriticalNesting--;
		
		if(!CriticalNesting){
			asm(CLI); 
		}
	}
}

__interrupt void ISR_SoftwareInterrupt(void){
	
	CriticalNesting ++;
	asm{
		LDA		CriticalNesting
		PSHA
		TSX
		STHX	CurrentStackPtr
	}
	
	CurrentStackPtr = Scheduller_Coperative(CurrentStackPtr);
	asm{
		LDHX	CurrentStackPtr
		TXS
		PULA
		STA		CriticalNesting
	}
	
}

__interrupt void ISR_TimerInterrupt(void){
	RTC_SC2 |=0x80;								//quitar bandera de interrupcion del timer
	CriticalNesting ++;
	asm{										//guarda el contexto
		LDA		CriticalNesting
		PSHA
		TSX
		STHX	CurrentStackPtr
	}
	//RTOS_DecrementTimers(); 
	CurrentStackPtr = RTOS_Scheduller(CurrentStackPtr);
	asm{
		LDHX	CurrentStackPtr
		TXS
		PULA
		STA		CriticalNesting
	}
}
