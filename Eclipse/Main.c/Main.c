/*
 * Main.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Muhammad Al-Barbary
 */

#include"LCD.h"
#include"ULTRASONIC.h"
#include"GPIO.h"
#include <avr/io.h>


int main(){
	uint32 Distance;
	ULTRASONIC_Init();
	LCD_Init();
	SREG |=(1<<7);
	while(1){
		Distance=ULTRASONIC_Distance();
		LCD_DisplayStringRowColumn(0,0,"Distance= ");
		LCD_IntToStr(Distance);
		if (Distance<10)
			LCD_DisplayStringRowColumn(0,11,"cm  ");
		else if (Distance<100)
			LCD_DisplayStringRowColumn(0,12,"cm ");
		else
			LCD_DisplayStringRowColumn(0,13,"cm");
	}
}
