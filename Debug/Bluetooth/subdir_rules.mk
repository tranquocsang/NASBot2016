################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Bluetooth/Bluetooth.obj: ../Bluetooth/Bluetooth.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/ti/ccsv6/tools/compiler/arm_5.1.6/include" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/dk-tm4c123g" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573" -g --gcc --define=ccs="ccs" --define=TARGET_IS_BLIZZARD_RA3 --define=PART_TM4C123GH6PM --display_error_number --diag_wrap=off --diag_warning=225 --preproc_with_compile --preproc_dependency="Bluetooth/Bluetooth.pp" --obj_directory="Bluetooth" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Bluetooth/uartstdio.obj: ../Bluetooth/uartstdio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/ti/ccsv6/tools/compiler/arm_5.1.6/include" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/dk-tm4c123g" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573" -g --gcc --define=ccs="ccs" --define=TARGET_IS_BLIZZARD_RA3 --define=PART_TM4C123GH6PM --display_error_number --diag_wrap=off --diag_warning=225 --preproc_with_compile --preproc_dependency="Bluetooth/uartstdio.pp" --obj_directory="Bluetooth" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Bluetooth/ustdlib.obj: ../Bluetooth/ustdlib.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccsv6/tools/compiler/arm_5.1.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/ti/ccsv6/tools/compiler/arm_5.1.6/include" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573/examples/boards/dk-tm4c123g" --include_path="D:/ti/TivaWare_C_Series-2.1.0.12573" -g --gcc --define=ccs="ccs" --define=TARGET_IS_BLIZZARD_RA3 --define=PART_TM4C123GH6PM --display_error_number --diag_wrap=off --diag_warning=225 --preproc_with_compile --preproc_dependency="Bluetooth/ustdlib.pp" --obj_directory="Bluetooth" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


