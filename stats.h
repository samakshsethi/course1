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
 * @file stats.c
 * @brief the header file for the coe that will provide the statistics related to the provided array
 * @author Samaksh Sethi
 * @date 10-04-2020
 *
 */


#ifndef __STATS_H__
#define __STATS_H__

/*print_statistics */

/* @brief Prints the statistics of an array like minimum, maximum, mean, and median.
 * @param array is the pointer to the first element of the array
 * @return Doesn't return any thing, only displays the statistics
 */
void print_statistics(unsigned char* array,unsigned int length);

/* print_array */

/* @brief Prints the array to the screen 
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Doesn't return any thing, only displays the array
 */
void print_array(unsigned char* array, unsigned int length);

/* find_median */

/* @brief Gives the median of the array 
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Returns the median of the array
 */
char find_median(unsigned char* array, unsigned int length);

/* find_mean */

/* @brief Gives the mean of the array 
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Returns the mean of the array
 */
char find_mean(unsigned char* array, unsigned int length);

/* find_minimum */

/* @brief Gives the minimum of the array 
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Returns the minimum of the array
 */
char find_minimum(unsigned char* array, unsigned int length);

/* find_maximum */

/* @brief Gives the maximum of the array 
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Returns the maximum of the array
 */
char find_maximum(unsigned char* array, unsigned int length);

/*sort_array */

/* @brief Sorts the array from largest to smallest
 * @param array is the pointer to the first element of the array
 * @param length is the length of array
 * @return Doesn't return any thing, only sorts the array
 */
void sort_array(unsigned char* array, unsigned int length);

#endif /* __STATS_H__ */
