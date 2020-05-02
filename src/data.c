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
 * @file data.c
 * @brief Contains atoi and itoa operations
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include "memory.h"
#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint32_t temp, f=0;
	size_t i=0;

	if(data<0){
		data*=-1;
		f=1;
	}
	while(data!=0){
		temp=data%base;
		if(temp<10)
			*(ptr+i)=temp+'0';
		else
			*(ptr+i)=temp-10+'a';
		data/=base;
		i++;
	}
	if(f){
		*(ptr+i)='-';
		i++;
	}
	*(ptr+i)='\0';
	ptr=my_reverse(ptr,i);
	return (uint8_t)i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	uint32_t temp=0, f=0;
	size_t i=0;

	if(*ptr=='-'){
		f=1;
		i++;
	}
	while(*(ptr+i)!='\0'){
		temp*=base;
		if(*(ptr+i)<='9')
			temp+=(*(ptr+i)-'0');
		else
			temp+=*(ptr+i)+10-'a';
		i++;
	}
	if(f){
		temp*=-1;
	}
	return temp;
}