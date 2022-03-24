
#include "AppTypes.h"
#include "Queue.h"
typedef enum{
    RUNNING =0,
    READY,
    BLOCKED
}TaskStatus, * TaskStatus_PTR;

typedef struct{
    uint_16     id;
    int_8 *     TaskName;
    TaskStatus  Status;
    uint_8      TaskPriority;
    void * taskParam
    TaskFunction TaskCallback; //No he denifino el tipo apuntador de funcion TaskFunction
    T_QUEUE_ELEMENT TaskQueueElement;
    pint_8        TaskStack;  //
    uint_16       TaskStackSize;
    uint_16       TaskActualStack; //ver que posicion quedo el stack pointer en la ejecucion de la tarea
    uint_16       TaskSleepTime;
}T_TCB, * T_TCB_PTR;