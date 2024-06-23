################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../debug_rom.asm 

C_SRCS += \
../Trap_Debug_tc0.c \
../kf_it.c \
../main.c \
../startup.c \
../vector.c 

OBJS += \
./Trap_Debug_tc0.o \
./debug_rom.o \
./kf_it.o \
./main.o \
./startup.o \
./vector.o 

C_DEPS += \
./Trap_Debug_tc0.d \
./debug_rom.d \
./kf_it.d \
./main.d \
./startup.d \
./vector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
#	@echo 'Invoking: ChipON C Lang Compiler'
	@clang  --target=kf32 -march=kf32gfd -c -MMD -MP -I"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM" -I"/home/chipon/chiponide32_1.0.20.3_13K/chiponide32/ChipONCC32/include" -I"/home/chipon/chiponide32_1.0.20.3_13K/chiponide32/ChipONCC32/include/Sys" -ffunction-sections -fdata-sections -nostdinc -nostdlib -save-temps=obj -Ofast -g -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-fputs -Wno-builtin-requires-header -Wno-invalid-source-encoding $< -o "$@"
	@echo 'Finished building: $<'
%.o: ../%.asm
	@echo 'Building file: $<'
#	@echo 'Invoking: ChipON Assembler'
	@kf32-as -MD $(dir $@)$(basename $(notdir $@)).d --kf32-arch=kf32df -I"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM" -I"/home/chipon/chiponide32_1.0.20.3_13K/chiponide32/ChipONCC32/include" -I"/home/chipon/chiponide32_1.0.20.3_13K/chiponide32/ChipONCC32/include/Sys" --defsym KF32DA2218SQVWS=1 -gstabs+ "$<" -o "$@"
	@echo 'Finished building: $<'

