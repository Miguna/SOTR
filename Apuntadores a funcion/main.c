#include "Button.h"

void OnButtonPressed(void);
void main(void){
    Button_SetCallback(OnButtonPressed);
    while(1){Button_Poll();}
}

void OnButtonPressed(void){printf("el boton fue presionado");}