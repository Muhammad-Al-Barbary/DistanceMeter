/*
 * ULTRASONIC.c
 *
 *  Created on: Oct 25, 2021
 *      Author: Muhammad Al-Barbary
 */

#include "ULTRASONIC.h"
#include "icu.h"
#include "GPIO.h"
#include <util/delay.h>
#include "StdTypes.h"

/*******************************************************************************
 *                      Variables Declarations                                   *
 *******************************************************************************/
uint16 g_time=0;
uint8 g_counter =0;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ULTRASONIC_Init (){
	Icu_ConfigType ICU_Config = {F_CPU_8,RISING};
	Icu_init(&ICU_Config);
	Icu_setCallBack(ULTRASONIC_EdgeProcessing);
	SetPin(Pin5,PortB,Output);
}

void ULTRASONIC_Trigger(){
	WritePin(Pin5,PortB,High);
	_delay_us(10);
	WritePin(Pin5,PortB,Low);
}

uint16 ULTRASONIC_Distance(){
	static uint16 distance = 0;
	ULTRASONIC_Trigger();
	if(g_counter==2){
	distance = g_time*0.017 +1;
	g_counter=0;
	}
	return distance;
}

void ULTRASONIC_EdgeProcessing(){

	g_counter++;
	if (g_counter==1){
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_counter==2) {
	g_time=Icu_getInputCaptureValue();
	Icu_setEdgeDetectionType(RISING);
	}

}



