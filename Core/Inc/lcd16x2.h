/*
 * lcd16x2.h
 *
 *  Created on: Dec 12, 2021
 *      Author: mjrsk
 */

#ifndef INC_LCD16X2_H_
#define INC_LCD16X2_H_

#include "stm32f4xx_hal.h"

#define LCD_UART_TIMEOUT 500

typedef enum DisplayCommand {
	CLEAR_DISPLAY = 0x01,
	CURSOR_RIGHT = 0x14,
	CURSOR_LEFT = 0x10,
	SCROLL_RIGHT = 0x1C,
	SCROLL_LEFT = 0x18,
	DISPLAY_ON = 0x0C,
	DISPLAY_OFF = 0x08,
	UNDERLINE_CURSOR_ON = 0x0E,
	BLINKING_CURSON_ON = 0x0D,
	SET_CURSOR_POSITION = 0x80
} DisplayCommand;

void LCD_Init(UART_HandleTypeDef *huart);
void LCD_ClearDisplay();
void LCD_SendCommand(DisplayCommand cmd);
void LCD_Line1();
void LCD_Line2();


#endif /* INC_LCD16X2_H_ */
