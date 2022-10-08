/******************************************************************************
 *
 * Project: FanController
 *
 * File Name: fanController.c
 *
 * Description: Source file for function used to simplify the code
 *
 * Author: Omar Ahmed Anwar Mansour
 *
 *******************************************************************************/


#include "fan_controller.h" /*FAN CONTROLLER HEADER FILE */
#include "lcd.h"			/*LCD HEADER FILE */

void FAN_CONTROLLER_FOR_DISPLAY(uint8 temp){
	/*
	 * DESCRIPTION
	 * 		MOVE THE CURSOR TO ROW 1 COL 11 TO DISLAY THE TEMPERATURE
	 * 		CHECK WHETHER TEMPERATURE IS LARGER THAN 100 TO DSPLAY CORRECTLY
	 */
	LCD_moveCursor(1,11);
	if (temp >= 100) {
		LCD_intgerToString(temp);
	}
	else {
		LCD_intgerToString(temp);
		LCD_displayCharacter(' '); /* CLEAR THE LEAST SIGNIFICANT DIGIT OF THE PREVIOUS NUM DISPLAYED */
	}
}


void FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(uint8 on_off){

	/*
	 * DESCRIPTION
	 * 		CHECK WHETHER FAN STATE IS TO DSPLAY CORRECTLY
	 * 		MOVE THE CURSOR TO ROW 0 COL 4 TO DISLAY THE STATEMENT OF THE STATE
	 *
	 */

	LCD_moveCursor(0, 4);

	if(on_off){
		LCD_displayString("FAN is ON");
		LCD_displayCharacter(' '); /* CLEAR THE LEAST SIGNIFICANT DIGIT OF THE PREVIOUS STATEMENT DISPLAYED */
	}
	else {
		LCD_displayString("FAN is OFF");
	}
}

