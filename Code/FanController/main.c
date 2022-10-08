/******************************************************************************
 *
 * Project: FanController
 *
 * File Name: main.c
 *
 * Description: Source file for the main project function
 *
 * Author: Omar Ahmed Anwar Mansour
 *
 *******************************************************************************/

#include "fan_controller.h"  	/*FAN CONTROLLER HEADER FILE */
#include "lcd.h"				/*LCD HEADER FILE */
#include "common_macros.h"		/* To use the macros like SET_BIT */
#include "adc.h"				/* ADC HEADER FILE */
#include "lm35_sensor.h"		/* TEMPERATURE SENSOR HEADER FILE */
#include "dc_motor.h"			/* DC MOTOR HEADER FILE */

int main(int argc, char **argv) {

	/* Configuration structure for the ADC
	 * 		name : adc
	 * 		Members : -> voltage Reference.
	 * 				  -> Presacaler.
	 */

	ADC_ConfigType adc = {Internal_Voltage_Reference,
			F_CPU_8
	};

	uint8 temp; /* Unsigned char variable to store the temperature read from Lm35_sensor. */

	LCD_init(); 	/* LCD Initialization function. */

	ADC_init(&adc); 	/* ADC initialization Function*/

	DcMotor_Init(); /*DC Motor initialization Function*/



	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_moveCursor(1, 4);
	LCD_displayString("Temp =    C");

	while(1){

		/* Get the current temperature sensed */
		temp = LM35_getTemperature();

		if(temp < 30 ){

			/*
			 * 	State Description (TEMPERATURE VALUE < 30)
			 * 		Display FAN IS OFF
			 * 		MOTOR IS IN STOP STATE
			 * 		DISPLAY TEMPERATURE VALUE
			 */

			FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(OFF);

			DcMotor_Rotate(STOP, 0);

			FAN_CONTROLLER_FOR_DISPLAY(temp);
		}

		else if (temp >= 30 && temp < 60) {

			/*
			 * 	State Description (TEMPERATURE VALUE [30,60) )
			 * 		Display FAN IS ON
			 * 		MOTOR IS ROTATING CLOCKWISE WITH 25% OF ITS MAX SPEED
			 * 		DISPLAY TEMPERATURE VALUE
			 */

			FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(ON);

			DcMotor_Rotate(ClockWise, 25);

			FAN_CONTROLLER_FOR_DISPLAY(temp);
		}

		else if (temp >= 60 && temp <90) {

			/*
			 * 	State Description (TEMPERATURE VALUE [60,90) )
			 * 		Display FAN IS ON
			 * 		MOTOR IS ROTATING CLOCKWISE WITH 50% OF ITS MAX SPEED
			 * 		DISPLAY TEMPERATURE VALUE
			 */

			FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(ON);

			DcMotor_Rotate(ClockWise, 50);

			FAN_CONTROLLER_FOR_DISPLAY(temp);
		}

		else if (temp >= 90 && temp < 120) {

			/*
			 * 	State Description (TEMPERATURE VALUE [90,120) )
			 * 		Display FAN IS ON
			 * 		MOTOR IS ROTATING CLOCKWISE WITH 75% OF ITS MAX SPEED
			 * 		DISPLAY TEMPERATURE VALUE
			 */

			FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(ON);

			DcMotor_Rotate(ClockWise, 75);

			FAN_CONTROLLER_FOR_DISPLAY(temp);
		}

		else if (temp >= 120) {

			/*
			 * 	State Description (TEMPERATURE VALUE >= 120)
			 * 		Display FAN IS ON
			 * 		MOTOR IS ROTATING CLOCKWISE WITH 100% OF ITS MAX SPEED
			 * 		DISPLAY TEMPERATURE VALUE
			 */

			FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(ON);

			DcMotor_Rotate(ClockWise, 100);

			FAN_CONTROLLER_FOR_DISPLAY(temp);
		}
	}
}

