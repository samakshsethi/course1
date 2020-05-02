/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Header file for data.c
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts from integer to ASCII
 *
 * @param Integer value
 * @param Pointer to final string of data
 * @param Base of integer
 *
 * @return void.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts from integer to ASCII
 *
 * @param Pointer to final string of data
 * @param Number of digits in integer
 * @param Base of integer
 *
 * @return void.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
