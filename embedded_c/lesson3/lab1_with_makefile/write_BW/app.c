#include "uart.h"
unsigned char string_buffer[50]="learn-in depth:AYA";
unsigned char string_buffer2[50]="learn-in depth:Abdulaziz";
void main(void){
 Uart_Send_String(&string_buffer[0]);
}