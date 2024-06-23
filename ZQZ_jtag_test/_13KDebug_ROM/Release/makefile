################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

-include $(C_DEPS)

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJCOPY_TARGET += \
_13KDebug_ROM.s19 \

OBJDUMP_LIST += \
_13KDebug_ROM.lst \


LD_SRCS =../KF32A156MQV.ld

EXECUTABLES	= _13KDebug_ROM.elf
# 所有目标
all: _13KDebug_ROM.elf secondary-outputs

# 工具调用
_13KDebug_ROM.elf: $(OBJS) $(USER_RELS) $(LD_SRCS)
	@echo 'Building target: $@'
#	@echo 'Invoking: ChipON Linker'
	@kf32-ld "@objects.list" $(USER_RELS) $(LIBS) -L"/home/chipon/chiponide32_1.0.20.3_13K/chiponide32/ChipONCC32/ccd1_issue/lib" -L"/home/chipon/chiponide32_1.0.20.3_13K/workspacekf32/_13KDebug_ROM" -lIQmath-R1 -lSeriesDIServices -lmath -lio -lstring -lstdlib -lctype -lcrtv3 -T../KF32A156MQV.ld --kf32-autoihex --kf32-arch=kf32df --kf32-nodisassemble --with-checksum-fill=0xFF --gc-sections -o  "_13KDebug_ROM.elf" -Map "_13KDebug_ROM.map"
	@echo 'Finished building target: $@'
#	@echo ' '

_13KDebug_ROM.s19: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjCopy'
	@kf32-objcopy -O srec --srec-len 16 --srec-forceS3 "_13KDebug_ROM.elf"   "_13KDebug_ROM.s19"
	@echo 'Finished building: $@'
#	@echo ' '

_13KDebug_ROM.lst: $(OBJS) $(EXECUTABLES) $(USER_RELS) $(LD_SRCS)
#	@echo 'Invoking: ChipON ObjDump'
	@kf32-objdump -S -l --section=.text --section=.data --section=.bss --kf32-arch=kf32df --section=.text.core0 --section=.text.core1 --section=.text.core2 --section=.data.core0 --section=.data.core1 --section=.data.core2 --section=.bss.core0 --section=.bss.core1 --section=.bss.core2 "_13KDebug_ROM.elf"   > "_13KDebug_ROM.lst"
	@echo 'Finished building: $@'
#	@echo ' '

# 其他目标
clean:
	-$(RM)  $(OBJS) $(EXECUTABLES) $(C_DEPS) _13KDebug_ROM.elf '$(basename $(OBJDUMP_LIST)).lst' '$(basename $(OBJCOPY_TARGET)).hex'   '$(basename $(OBJCOPY_TARGET)).bin'  '$(basename $(OBJCOPY_TARGET)).s19' '$(basename $(OBJCOPY_TARGET)).map'
#	-@echo ' '

secondary-outputs: _13KDebug_ROM.lst _13KDebug_ROM.s19

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
