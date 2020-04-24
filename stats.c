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
 * @brief the code will provide the statistics related to the provided array
 * @author Samaksh Sethi
 * @date 10-04-2020
 *
 */


#include <stdio.h>
//#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
int sum=0, mean=0;

void print_statistics(unsigned char* array,unsigned int length);
void print_array(unsigned char* array, unsigned int length);
unsigned char find_median(unsigned char* array,unsigned int length);
unsigned char find_mean(unsigned char* array,unsigned int length);
unsigned char find_minimum(unsigned char* array, unsigned int length);
unsigned char find_maximum(unsigned char* array, unsigned int length);
void sort_array(unsigned char* array, int length);

void print_statistics(unsigned char* array,unsigned int length){
	printf("Mean: ");
	printf("%d",find_mean(array,length));
	printf("\nMedian: ");
	printf("%d",find_median(array,length));
	printf("\nMinimum: ");
	printf("%d",find_minimum(array,length));
	printf("\nMaximum: ");
	printf("%d",find_maximum(array,length));
}

void print_array(unsigned char* array, unsigned int length){
	printf("\n\n");
	for(int i=0;i<length;i++){
		printf("%d",*(array+i));
		printf(", ");
	}
	printf("\n\n");
}

unsigned char find_median(unsigned char* array,unsigned int length){
	sort_array(array, length);
	return(*(array+(length/2)-1));
}

unsigned char find_mean(unsigned char* array,unsigned int length){
	for(int i=0;i<length;i++){
		sum+=*(array+i);
	}
	mean=sum/length;
	return((unsigned char)mean);
}

unsigned char find_minimum(unsigned char* array, unsigned int length){
	sort_array(array, length);
	return(*(array+length-1));
}

unsigned char find_maximum(unsigned char* array, unsigned int length){
	sort_array(array, length);
	return(*array);
}

void sort_array(unsigned char array[], int length){
	int i=0,j=0,temp;
	for(i=0;i<40;i++) {
		for(j=0;j<40-i-1;j++){
			if(*(array+j)<*(array+j+1)){
				temp=*(array+j);
     			*(array+j)=*(array+j+1);
          		*(array+j+1)=temp;
            		}
       		}
    	}
}

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                            	114, 88,   45,  76, 123,  87,  25,  23,
                              	200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	unsigned char *ptr;
	ptr=test;
	print_array(ptr, SIZE);
	print_statistics(ptr, SIZE);
	sort_array(ptr, SIZE);
	print_array(ptr, SIZE);
}
