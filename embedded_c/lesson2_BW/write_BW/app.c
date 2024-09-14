#include "uart.h"
unsigned char string_buffer[50]="learn-in depth:AYA";
void main(void){
 Uart_Send_String(&string_buffer[0]);
}