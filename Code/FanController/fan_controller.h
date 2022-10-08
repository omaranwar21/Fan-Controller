/******************************************************************************
 *
 * Project: FanController
 *
 * File Name: fanController.h
 *
 * Description: Header file for function used to simplify the code
 *
 * Author: Omar Ahmed Anwar Mansour
 *
 *******************************************************************************/

#ifndef FAN_CONTROLLER_H_
#define FAN_CONTROLLER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define OFF 	0
#define ON 		1

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * 		to display correctly THE TEMPERATURE on LCD
 */
void FAN_CONTROLLER_FOR_DISPLAY(uint8 temp);

/*
 * Description:
 * 		to display correctly FAN STATE on LCD
 */
void FAN_CONTROLLER_FOR_DISPLAY_FAN_STATE(uint8 on_off);


#endif /* FAN_CONTROLLER_H_ */
