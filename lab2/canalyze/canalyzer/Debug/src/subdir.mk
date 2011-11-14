################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/canalyzer.c \
../src/namelist.c \
../src/testnl.c 

OBJS += \
./src/canalyzer.o \
./src/namelist.o \
./src/testnl.o 

C_DEPS += \
./src/canalyzer.d \
./src/namelist.d \
./src/testnl.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


