 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ULTRASONIC.h
 *
 * Description: Header file for the Ultrasonic driver
 *
 * Author: Muhammad Al-Barbary
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "StdTypes.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Description:
   Initialize the ICU driver as required.
   Setup the ICU call back function.
   Setup the direction for the trigger pin as
   output pin through the GPIO driver.
*/

void ULTRASONIC_Init ();


/* Description:
   Send the Trigger pulse to the Ultrasonic */
void ULTRASONIC_Trigger();


/*Description:
  Send the trigger pulse by using Ultrasonic_Trigger function.
  Start the measurements by the ICU from this moment.*/
uint16 ULTRASONIC_Distance();

/*Description
  This is the call back function called by the ICU driver.
  This is used to calculate the high time (pulse time)
  generated by the ultrasonic sensor.*/
void ULTRASONIC_EdgeProcessing();

#endif /* ULTRASONIC_H_ */
