#ifndef __BUTTON_H__
#define __BUTTON_H__
#define PORT PTAD
#define GPIO 0x01

typedef void (*OnPress)(void);
void Button_Set_Callback(OnPress);
void Button_Poll(void);
#endif