################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/gint.c \
../source/semihost_hardfault.c 

OBJS += \
./source/gint.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/gint.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\board" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\source" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\utilities" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\drivers" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\device" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\startup" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\component\uart" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\component\lists" -I"C:\Users\Baptiste\Documents\ENSEA\3D\S10_011_Projet\IDE\lpcxpresso55s69_gint\CMSIS" -O0 -fno-common -g3 -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


