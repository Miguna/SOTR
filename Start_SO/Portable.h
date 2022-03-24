puint_8 Portable_InitTaskContext(puint_8 Stack, TaskFunction Function);
void Portable:RestoreManualContext();


#define Portable_SaveContex()       asm(TXT);\
                                    asm(STHX CurrentStackPtr)
#define Postable_RestoreContext()   asm(LDHX Registro que  no se cual es);\
                                    asm{TXT}