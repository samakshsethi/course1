#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for running HOST and a MSP432 systems
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Generates the preprocessed output of all files
#      <FILE>.asm - Generates the final output executable
#      <FILE>.o - Generates the object file (without linking)
#      <FILE>.d - Generates the dependency file
#      compile-all - Builds all object files (without linking)
#      build - Builds all object files into a final executable
#      clean - Removes all generated files
#
# Platform Overrides:
#       CPU = cortex-m4
#		ARCH = thumb
#		SPECS = nosys.specs
#		ARCH_TYPE = armv7e-m
#		ABI = hard
#		FPU = fpv4-sp-d16
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2
OBJS = $(SRCS:.c=.o)
OBJS_I = $(SRCS:.c=.i)
OBJS_ASM = $(SRCS:.c=.asm)
OBJS_D = $(SRCS:.c=.d)

ifeq ($(PLATFORM),MSP432)

# PLATFORM=MSP432

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
ARCH_TYPE = armv7e-m
ABI = hard
FPU = fpv4-sp-d16

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
PLTFRM_FLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=$(ARCH_TYPE) -mfloat-abi=$(ABI) -mfpu=$(FPU)
CPPFLAGS = -Wall -Werror -g -O0 -std=c99
CFLAGS = $(CPPFLAGS) $(PLTFRM_FLAGS) $(INCLUDES) -DMSP432 
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

else

# PLATFORM=HOST

CC = gcc
CPPFLAGS = -Wall -Werror -g -O0 -std=c99
CFLAGS = $(CPPFLAGS) $(INCLUDES) -DHOST
LDFLAGS = -Wl,-Map=$(TARGET).map

#Changing SRCS to only files related to HOST machines
SRCS = main.c \
	memory.c

endif

%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

$(TARGET).asm : $(TARGET).out
	objdump -S -d $^ > $@

%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) $(CFLAGS) -MF"$@" -MG -MM -MP -MT"$@" -MT"$(OBJS)" "$<"

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out $(OBJS_D)
	size $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJS_I) $(OBJS_ASM) $(OBJS_D) $(TARGET).out $(TARGET).map $(TARGET).asm