/*
 * lcd16x2.c
 *
 *  Created on: Dec 12, 2021
 *      Author: mjrsk
 */


#include "lcd16x2.h"

#define DISPLAY_CONTROL_CHAR 0xfe
#define CONFIG_CONTROL_CHAR 0x7c
#define LCD_LINE_1 0
#define LCD_LINE_2 64

static UART_HandleTypeDef *lcd_UartHandlePtr;

void LCD_Init(UART_HandleTypeDef *huart) {
	lcd_UartHandlePtr = huart;
	HAL_Delay(500);
	LCD_ClearDisplay();
}

void LCD_ClearDisplay() {
	LCD_SendCommand(CLEAR_DISPLAY);
}

void LCD_SendCommand(DisplayCommand cmd) {
	uint8_t buf[] = { DISPLAY_CONTROL_CHAR, cmd };
	HAL_UART_Transmit(lcd_UartHandlePtr, buf, 2, LCD_UART_TIMEOUT);
}

void LCD_Line1() {
	LCD_SendCommand(SET_CURSOR_POSITION + LCD_LINE_1);
}

void LCD_Line2() {
	LCD_SendCommand(SET_CURSOR_POSITION + LCD_LINE_2);
}
