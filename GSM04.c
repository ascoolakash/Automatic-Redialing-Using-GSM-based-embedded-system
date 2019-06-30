/*
 * GSM04.c
 *
 *  Created on: 01-Jul-2013
 *      Author: Akash Saurabh
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <uart_lib.h>
#include <stdio.h>
char A[200]=" ",index=0;
int delay;
ISR(USART_RXC_vect) {
	A[index] = UDR;
	if (A[index]==10)index = 0;
	else index++;
}

int main() {
	set_uartbaud(9600);
	enable_uart_rxcint();
	sendchar_uart(0x1a);
	sei();
	while(1){
		sendstring_uart("ATD09832165526;\r\n");
		_delay_ms(1000);
		delay=0;
		while(1){
			sendstring_uart("AT+CLCC\r\n"); _delay_ms(100);
			if(strncmp(A+5,": 1,0,3,0,0,",10)==0)break;
			if(delay>100)break;
			delay++;
		}
		sendstring_uart("ATH\r\n");
		_delay_ms(2000);
	}
	return 0;
}
