#ifndef TASK_H_
#define TASK_H_

#include "AppTypes.h"
#include "Queue.h"


#define TASK_OK			0
#define	TASK_ERROR_UNKNOW						TASK_BASE_ERROR | BASE_ERROR_UNKNOW
#define	TASK_ERROR_NULL_PARAM					TASK_BASE_ERROR | BASE_ERROR_NULL_PARAM
#define	TASK_ERROR_EMPTY						TASK_BASE_ERROR | BASE_ERROR_EMPTY
#define TASK_ERROR_PARAM_OUT_OF_RANGE			TASK_BASE_ERROR | BASE_ERROR_PARAM_OUT_OF_RANGE

typedef	void (*TaskFunction)(void * Param);

typedef enum{
    RUNNING =0,
    READY,
    BLOCKED
}TaskStatus, * TaskStatus_PTR;

typedef struct{
    uint_16         Id;         		//**
    pint_8          TaskName;    		//**
    TaskStatus      Status;   
    uint_8          TaskPriority;		//**
    pvi             TaskParam;			//**
    TaskFunction    TaskCallback; 		//**
    T_QUEUE_ELEMENT TaskQueueElement;	
    pint_8          TaskStack;  		//**
    uint_16         TaskStackSize;		//**
    uint_16         TaskActualStack; 
    uint_16         TaskSleepTime;
    uint_16         TaskActualTask;
    //** --> Parametros dados en la inicializacion de la tarea por el usuario.
}T_TCB, * T_TCB_PTR;
/*
 * 
 * Defincion de funciones del modulo
 * 
 */
T_TCB_PTR Task_GetActualTask(vi);
vi Task_SetActualTask(T_TCB_PTR Task);
uint_16 Task_Create(T_TCB_PTR TaskHandler, uint_16 Id, pint_8 Name, uint_8 Priority, pint_8 Stack, uint_16 StackSize, TaskFunction Function, void * Param );



#endif
