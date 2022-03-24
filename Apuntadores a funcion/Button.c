#include "Button.h"

OnPress callbackfunction = NULL;
char pressed=0;

void Button_SetCallback(OnPress f){
    callbackfunction=f;
}

void Button_poll(void){
    if((PORT&GPIO!=0){
        if(pressed==0){
            pressed==1;
            if(callbackfunction){
                callbackfunction();
            }
        }
    }else{
        pressed=0;
    }
}