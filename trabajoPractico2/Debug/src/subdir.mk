################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/arrayPassenger.c \
../src/funciones.c \
../src/trabajoPractico2.c 

C_DEPS += \
./src/arrayPassenger.d \
./src/funciones.d \
./src/trabajoPractico2.d 

OBJS += \
./src/arrayPassenger.o \
./src/funciones.o \
./src/trabajoPractico2.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/arrayPassenger.d ./src/arrayPassenger.o ./src/funciones.d ./src/funciones.o ./src/trabajoPractico2.d ./src/trabajoPractico2.o

.PHONY: clean-src

