#ifndef RTOS_H_
#define RTOS_H_
/*
 * 
 * Inclusion de librerias
 * 
 */
#include "AppTypes.h"
#include "Scheduller.h"
#include "Queue.h"
/*
 * 
 * Definicion de constantes del modulo
 * 
 */
#define RTOS_SYSTEM_PRIORITIES  8
#define RTOS_MIN_PRIORITY RTOS_SYSTEM_PRIORITIES - 1
#define RTOS_MAX_PRIORITY     0

#define	RTOS_MIN_STACK_SIZE			64 //Preferiblemnte de 64

#define RTOS_IDLE_TASK_PRIORITY		RTOS_SYSTEM_PRIORITIES
#define	RTOS_IDLE_TASK_STACK_SIZE	RTOS_MIN_STACK_SIZE
#define	RTOS_IDLE_TASK_ID			255
#define RTOS_IDLE_TASK_NAME			"Idle Task"

uint_16 RTOS_Init(vi);
uint_16 RTOS_Start(vi);
//T_QUEUE_HANDLER ReadyTaskList[RTOS_SYSTEM_PRIORITIES];

#endif
