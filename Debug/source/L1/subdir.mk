################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/L1/Application.c \
../source/L1/COM.c \
../source/L1/COMMUNICATION.c \
../source/L1/INDICATOR.c \
../source/L1/TEMP.c \
../source/L1/TIME.c 

C_DEPS += \
./source/L1/Application.d \
./source/L1/COM.d \
./source/L1/COMMUNICATION.d \
./source/L1/INDICATOR.d \
./source/L1/TEMP.d \
./source/L1/TIME.d 

OBJS += \
./source/L1/Application.o \
./source/L1/COM.o \
./source/L1/COMMUNICATION.o \
./source/L1/INDICATOR.o \
./source/L1/TEMP.o \
./source/L1/TIME.o 


# Each subdirectory must supply rules for building sources it contributes
source/L1/%.o: ../source/L1/%.c source/L1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\codigos\MCU\TDII\TP1\board" -I"D:\codigos\MCU\TDII\TP1\source" -I"D:\codigos\MCU\TDII\TP1\component\uart" -I"D:\codigos\MCU\TDII\TP1\drivers" -I"D:\codigos\MCU\TDII\TP1\CMSIS" -I"D:\codigos\MCU\TDII\TP1\device" -I"D:\codigos\MCU\TDII\TP1\utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-L1

clean-source-2f-L1:
	-$(RM) ./source/L1/Application.d ./source/L1/Application.o ./source/L1/COM.d ./source/L1/COM.o ./source/L1/COMMUNICATION.d ./source/L1/COMMUNICATION.o ./source/L1/INDICATOR.d ./source/L1/INDICATOR.o ./source/L1/TEMP.d ./source/L1/TEMP.o ./source/L1/TIME.d ./source/L1/TIME.o

.PHONY: clean-source-2f-L1

