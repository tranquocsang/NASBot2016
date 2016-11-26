################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/ti/ccsv6/tools/compiler/arm_5.1.6

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./SystemConfig.obj" \
"./main.obj" \
"./startup_ccs.obj" \
"./Timer/Timer.obj" \
"./Sensor/Line_Sensor.obj" \
"./STR/speed_control.obj" \
"./QEI/qei.obj" \
"./PID/PID.obj" \
"./LineFollow/line_follow.obj" \
"./Button/Button.obj" \
"./Bluetooth/Bluetooth.obj" \
"./Bluetooth/uartstdio.obj" \
"./Bluetooth/ustdlib.obj" \
"../tm4c123gh6pm.cmd" \
-l"libc.a" \
-l"D:\ti\TivaWare_C_Series-2.1.0.12573\driverlib\ccs\Debug\driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Timer/subdir_vars.mk
-include Sensor/subdir_vars.mk
-include STR/subdir_vars.mk
-include QEI/subdir_vars.mk
-include PID/subdir_vars.mk
-include LineFollow/subdir_vars.mk
-include Button/subdir_vars.mk
-include Bluetooth/subdir_vars.mk
-include subdir_rules.mk
-include Timer/subdir_rules.mk
-include Sensor/subdir_rules.mk
-include STR/subdir_rules.mk
-include QEI/subdir_rules.mk
-include PID/subdir_rules.mk
-include LineFollow/subdir_rules.mk
-include Button/subdir_rules.mk
-include Bluetooth/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
RYA\ 2015.out \

EXE_OUTPUTS__QUOTED += \
"RYA 2015.out" \

BIN_OUTPUTS += \
RYA\ 2015.hex \

BIN_OUTPUTS__QUOTED += \
"RYA 2015.hex" \


# All Target
all: RYA\ 2015.out

# Tool invocations
RYA\ 2015.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"D:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --gcc --define=ccs="ccs" --define=TARGET_IS_BLIZZARD_RA3 --define=PART_TM4C123GH6PM --display_error_number --diag_wrap=off --diag_warning=225 -z -m"RYA 2015.map" --heap_size=0 --stack_size=4096 -i"D:/ti/ccsv6/tools/compiler/arm_5.1.6/lib" -i"D:/ti/ccsv6/tools/compiler/arm_5.1.6/include" --reread_libs --display_error_number --diag_wrap=off --warn_sections --xml_link_info="RYA 2015_linkInfo.xml" --rom_model -o "RYA 2015.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

RYA\ 2015.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"D:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armhex"  -o "RYA 2015.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "SystemConfig.pp" "main.pp" "startup_ccs.pp" "Timer\Timer.pp" "Sensor\Line_Sensor.pp" "STR\speed_control.pp" "QEI\qei.pp" "PID\PID.pp" "LineFollow\line_follow.pp" "Button\Button.pp" "Bluetooth\Bluetooth.pp" "Bluetooth\uartstdio.pp" "Bluetooth\ustdlib.pp" 
	-$(RM) "SystemConfig.obj" "main.obj" "startup_ccs.obj" "Timer\Timer.obj" "Sensor\Line_Sensor.obj" "STR\speed_control.obj" "QEI\qei.obj" "PID\PID.obj" "LineFollow\line_follow.obj" "Button\Button.obj" "Bluetooth\Bluetooth.obj" "Bluetooth\uartstdio.obj" "Bluetooth\ustdlib.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

