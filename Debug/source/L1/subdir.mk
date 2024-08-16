################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/L1/Application.c 

C_DEPS += \
./source/L1/Application.d 

OBJS += \
./source/L1/Application.o 


# Each subdirectory must supply rules for building sources it contributes
source/L1/%.o: ../source/L1/%.c source/L1/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC845M301JBD48 -DCPU_LPC845M301JBD48_cm0plus -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DPRINTF_FLOAT_ENABLE=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\codigos\MCU\TDII\TP1\board" -I"D:\codigos\MCU\TDII\TP1\source" -I"D:\codigos\MCU\TDII\TP1\component\uart" -I"D:\codigos\MCU\TDII\TP1\drivers" -I"D:\codigos\MCU\TDII\TP1\CMSIS" -I"D:\codigos\MCU\TDII\TP1\device" -I"D:\codigos\MCU\TDII\TP1\utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-L1

clean-source-2f-L1:
	-$(RM) ./source/L1/Application.d ./source/L1/Application.o

.PHONY: clean-source-2f-L1

