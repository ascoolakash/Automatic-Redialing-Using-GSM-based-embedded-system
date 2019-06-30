/*
 * uart_lib.h
 *
 *  Created on: Apr 27, 2011
 *      Author: simplifix
 */
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 4000000// Clock Speed

void set_uartbaud(int);

void set_usrt();

void disable_uart();

void enable_uart_txcint();

void enable_uart_rxcint();

void enable_uart_udreint();

void disable_uart_txcint();

void disable_uart_rxcint();

void disable_uart_udreint();

void sendchar_uart(char);

char getchar_uart();

void sendstring_uart(char[]);

