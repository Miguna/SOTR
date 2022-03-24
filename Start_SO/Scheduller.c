#include "AppTypes.h"
#include "Scheduller.h"

uint_16 Scheduller_Coperative(uint_16 ActualTaskSP){
    T_TCB_PTR Task = NULL;
    Task = Task_GetActualTask();
    if(Task != NULL){
        Task->TastActualStack = ActualTask;
    }
}
uint_16 Scheduller_SetTaskToReadyQueue(){}

uint_16 SchedullerInit();