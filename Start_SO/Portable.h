#ifndef __PORTABLE_H
#define __PORTABLE_H
/*
 * 
 * Inclusion de librerias
 * 
 */
#include "AppTypes.h"
#include "Scheduller.h"
/*
 * 
 * Definicion de constantes del modulo
 * 
 */
#define Portable_SoftwareInterrupt()	asm(SWI)
/*
 * 
 * Definicion de constantes internas del modulo.
 * 
 */

#define Portable_SaveContext()			asm(TSX):\
										asm(STHX CurrentStackPtr)
#define Portable_RestoreContext()		asm(LDHX CurrentStackPtr):\
										asm(TXS)

#define Portable_SoftwareInterrupt()	asm(SWI)
/*
 * 
 * Deficion de tipos de datos del modulo
 * 
 */
typedef	void (*TaskFunction)(void * Param);
/*
 * 
 * Deficion de funciones del modulo.
 * 
 */

puint_8 Portable_InitTaskContext(puint_8 Stack, TaskFunction Function, pvi Param);
void Portable:RestoreManualContext();
vi Portable_InitTickRTC(vi);
vi Portable_DisableInterrupts(vi);
vi Portable_EnableInterrupts(vi);
__interrupt void ISR_SoftwareInterrupt(vi);
__interrupt void ISR_TimerInterrupt(vi);

uint_16	Scheduller_Coperative(uint_16 ActualTaskSP);

#endif