################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../App_prog.c \
../CLCD_prog.c \
../DIO_prog.c \
../GIE_prog.c \
../KPD_prog.c \
../L298_prog.c \
../LM35_prog.c \
../PORT_prog.c \
../TIMER1_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./App_prog.o \
./CLCD_prog.o \
./DIO_prog.o \
./GIE_prog.o \
./KPD_prog.o \
./L298_prog.o \
./LM35_prog.o \
./PORT_prog.o \
./TIMER1_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./App_prog.d \
./CLCD_prog.d \
./DIO_prog.d \
./GIE_prog.d \
./KPD_prog.d \
./L298_prog.d \
./LM35_prog.d \
./PORT_prog.d \
./TIMER1_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


