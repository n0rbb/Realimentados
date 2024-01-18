###########################################################################
## Makefile generated for component 'control_motor'. 
## 
## Makefile     : control_motor.mk
## Generated on : Wed Jan 17 11:11:00 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/control_motor.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = control_motor
MAKEFILE                  = control_motor.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/miqui/OneDrive/UNIVER~1/423-24~1/REALIM~1/PRACTI~1/REALIZ~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = control_motor_comp.rsp
CMD_FILE                  = control_motor.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                    = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                      = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_NAME_WITHOUT_EXTN = $(basename $(PRODUCT))
PRODUCT_BIN               = $(PRODUCT_NAME_WITHOUT_EXTN).bin
PRODUCT_HEX               = $(PRODUCT_NAME_WITHOUT_EXTN).hex
CPFLAGS                   = -O binary
SHELL                     = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =



#---------------------------
# Model-Specific Options
#---------------------------

ASFLAGS = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  -Wall -x assembler-with-cpp $(ASFLAGS_ADDITIONAL) $(DEFINES) $(INCLUDES) -c

CFLAGS = $(FDATASECTIONS_FLG) -Wall -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  -c -O0 -g

LDFLAGS = -Wl,--gc-sections -Wl,-Map="$(PRODUCT_NAME).map" -g

SHAREDLIB_LDFLAGS = -g

CPPFLAGS = -std=gnu++14 -fno-rtti -fno-exceptions $(FDATASECTIONS_FLG) -Wall -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  -c -O0 -g

CPP_LDFLAGS = -Wl,--gc-sections -Wl,-Map="$(PRODUCT_NAME).map" -g

CPP_SHAREDLIB_LDFLAGS = -g

ARFLAGS = ruvs

OBJCOPYFLAGS_BIN = -O binary $(PRODUCT) $(PRODUCT_BIN)

OBJCOPYFLAGS_HEX = -O ihex $(PRODUCT) $(PRODUCT_HEX)

EXESIZE_FLAGS = $(PRODUCT)

DOWNLOAD_FLAGS = 

EXECUTE_FLAGS = 

MAKE_FLAGS = -f $(MAKEFILE)

###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/control_motor.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DONESTEPFCN=1 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DXCP_DAQ_SUPPORT -DXCP_CALIBRATION_SUPPORT -DXCP_TIMESTAMP_SUPPORT -DXCP_SET_MTA_SUPPORT -DEXTMODE_XCP_TRIGGER_SUPPORT -DINTERNAL_XCP_MEM_BLOCK_1_SIZE=160 -DINTERNAL_XCP_MEM_BLOCK_1_NUMBER=1 -DINTERNAL_XCP_MEM_BLOCK_2_SIZE=168 -DINTERNAL_XCP_MEM_BLOCK_2_NUMBER=5 -DINTERNAL_XCP_MEM_BLOCK_3_SIZE=40 -DINTERNAL_XCP_MEM_BLOCK_3_NUMBER=5 -DINTERNAL_XCP_MEM_RESERVED_POOLS_TOTAL_SIZE=2194 -DINTERNAL_XCP_MEM_RESERVED_POOLS_NUMBER=6 -DXCP_MEM_DAQ_RESERVED_POOL_BLOCKS_NUMBER=3 -DXCP_MEM_DAQ_RESERVED_POOLS_NUMBER=2 -DXCP_MIN_EVENT_NO_RESERVED_POOL=2 -DXCP_MAX_CTO_SIZE=255 -DXCP_MAX_DTO_SIZE=65532 -DXCP_MAX_ODT_ENTRY_SIZE=255 -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=2000 -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=0
DEFINES_SKIPFORSIL = -DARM_MATH_CM4 -DCOMPONENT_FLASHIAP=1 -DCOMPONENT_NSPE=1 -DCOMPONENT_PSA_SRV_EMUL=1 -DCOMPONENT_PSA_SRV_IMPL=1 -DDEVICE_ANALOGIN=1 -DDEVICE_ERROR_RED=1 -DDEVICE_FLASH=1 -DDEVICE_I2C=1 -DDEVICE_I2CSLAVE=1 -DDEVICE_I2C_ASYNCH=1 -DDEVICE_INTERRUPTIN=1 -DDEVICE_LPTICKER=1 -DDEVICE_MPU=1 -DDEVICE_PORTIN=1 -DDEVICE_PORTINOUT=1 -DDEVICE_PORTOUT=1 -DDEVICE_PWMOUT=1 -DDEVICE_RTC=1 -DDEVICE_SERIAL=1 -DDEVICE_SERIAL_ASYNCH=1 -DDEVICE_SERIAL_FC=1 -DDEVICE_SLEEP=1 -DDEVICE_SPI=1 -DDEVICE_SPISLAVE=1 -DDEVICE_SPI_ASYNCH=1 -DDEVICE_STDIO_MESSAGES=1 -DDEVICE_USTICKER=1 -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DMBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE=9600 -DMBED_RAM_SIZE=0x20000 -DMBED_RAM_START=0x20000000 -DMBED_ROM_SIZE=0x80000 -DMBED_ROM_START=0x8000000 -DMBED_TRAP_ERRORS_ENABLED=1 -DNULL=0 -DTARGET_CORTEX -DTARGET_CORTEX_M -DTARGET_FAMILY_STM32 -DTARGET_FF_ARDUINO -DTARGET_FF_MORPHO -DTARGET_LIKE_CORTEX_M4 -DTARGET_LIKE_MBED -DTARGET_M4 -DTARGET_M4F -DTARGET_NAME=NUCLEO_F411RE -DTARGET_NUCLEO_F411RE -DTARGET_RELEASE -DTARGET_STM32F411RE -DTARGET_STM32F411xE -DTARGET_STM32F4 -DTARGET_STM -DTARGET_UVISOR_UNSUPPORTED -DTOOLCHAIN_GCC -DTOOLCHAIN_GCC_ARM -DTOOLCHAIN_object -DTRANSACTION_QUEUE_SIZE_SPI=2 -DUSBHOST_OTHER -DUSB_STM_HAL -DXCP_CUSTOM_PLATFORM -D__CORTEX_M4 -D__FPU_PRESENT=1 -D__FPU_USED=1U -D__MBED__=1 -DSTACK_SIZE=64 -DRT -DMW_RTIOSTREAM_BAUDRATE="115200"
DEFINES_STANDARD = -DMODEL=control_motor -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/MW_digitalIO.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/MW_PWM.cpp $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c $(START_DIR)/control_motor_ert_rtw/control_motor.c $(START_DIR)/control_motor_ert_rtw/control_motor_data.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_serial.c $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/stmnucleo/STM32F411RE/src/mw_mbed_interface.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/BufferedSerial.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/GCC/mbed_syscalls.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/xcp/src/sys_arch.c C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/xcp_platform_timer_mbed.c C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/rtiostream_serial_mbed.cpp

MAIN_SRC = $(START_DIR)/control_motor_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_digitalIO.o MW_PWM.o xcp_ext_mode.o control_motor.o control_motor_data.o xcp_ext_common.o xcp_ext_classic_trigger.o xcp.o xcp_standard.o xcp_daq.o xcp_calibration.o xcp_fifo.o xcp_transport.o xcp_mem_default.o xcp_drv_rtiostream.o xcp_utils.o xcp_frame_serial.o xcp_ext_param_default_serial.o mw_mbed_interface.o BufferedSerial.o mbed_syscalls.o SysTickScheduler.o m3m4m4f_multitasking.o sys_arch.o xcp_platform_timer_mbed.o rtiostream_serial_mbed.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/ProgramData/MATLAB/SupportPackages/R2023b/3P.instrset/cmsis_dsp.instrset/Lib/GCC/arm_cortexm4ldfsp_math/libCMSISDSP.a

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fdata-sections -ffunction-sections -fmessage-length=0 -fno-delete-null-pointer-checks -fomit-frame-pointer -funsigned-char -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wvla -include mbed_config.h
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------
# Linker
#-----------

LDFLAGS_ = @C:\Users\miqui\OneDrive\UNIVER~1\423-24~1\REALIM~1\PRACTI~1\REALIZ~1\CONTRO~2\MBED_O~1.RSP
LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry=Reset_Handler --specs=nano.specs --specs=nosys.specs -T"C:\ProgramData\MATLAB\SupportPackages\R2023b\toolbox\target\supportpackages\stmnucleo\registry\../mbed/NUCLEO_F411RE/TOOLCHAIN_GCC_ARM/STM32F411XE.ld"

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = @C:\Users\miqui\OneDrive\UNIVER~1\423-24~1\REALIM~1\PRACTI~1\REALIZ~1\CONTRO~2\MBED_O~1.RSP
SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry=Reset_Handler --specs=nano.specs --specs=nosys.specs -T"C:\ProgramData\MATLAB\SupportPackages\R2023b\toolbox\target\supportpackages\stmnucleo\registry\../mbed/NUCLEO_F411RE/TOOLCHAIN_GCC_ARM/STM32F411XE.ld"

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fdata-sections -ffunction-sections -fmessage-length=0 -fno-delete-null-pointer-checks -fomit-frame-pointer -funsigned-char -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers -Wvla -include mbed_config.h
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = @C:\Users\miqui\OneDrive\UNIVER~1\423-24~1\REALIM~1\PRACTI~1\REALIZ~1\CONTRO~2\MBED_O~1.RSP
CPP_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry=Reset_Handler --specs=nano.specs --specs=nosys.specs -T"C:\ProgramData\MATLAB\SupportPackages\R2023b\toolbox\target\supportpackages\stmnucleo\registry\../mbed/NUCLEO_F411RE/TOOLCHAIN_GCC_ARM/STM32F411XE.ld"

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = @C:\Users\miqui\OneDrive\UNIVER~1\423-24~1\REALIM~1\PRACTI~1\REALIZ~1\CONTRO~2\MBED_O~1.RSP
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard --entry=Reset_Handler --specs=nano.specs --specs=nosys.specs -T"C:\ProgramData\MATLAB\SupportPackages\R2023b\toolbox\target\supportpackages\stmnucleo\registry\../mbed/NUCLEO_F411RE/TOOLCHAIN_GCC_ARM/STM32F411XE.ld"

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include mw_gnu_arm_tools_path.mk
-include ../mw_gnu_arm_tools_path.mk
-include ../../mw_gnu_arm_tools_path.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	@echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	@echo "### Done invoking postbuild tool."
	@echo "### Invoking postbuild tool "Executable Size" ..."
	$(EXESIZE) $(EXESIZE_FLAGS)
	@echo "### Done invoking postbuild tool."


download : postbuild


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/control_motor_ert_rtw/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_digitalIO.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/MW_digitalIO.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


MW_PWM.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/MW_PWM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xcp_ext_mode.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_mode.c
	$(CC) $(CFLAGS) -o "$@" "$<"


control_motor.o : $(START_DIR)/control_motor_ert_rtw/control_motor.c
	$(CC) $(CFLAGS) -o "$@" "$<"


control_motor_data.o : $(START_DIR)/control_motor_ert_rtw/control_motor_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ert_main.o : $(START_DIR)/control_motor_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_common.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_common.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_classic_trigger.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_classic_trigger.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_standard.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_standard.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_daq.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_daq.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_calibration.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/protocol/src/xcp_calibration.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_fifo.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_fifo.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_transport.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_transport.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_mem_default.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_mem_default.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_drv_rtiostream.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/platform/default/xcp_drv_rtiostream.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_utils.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/common/xcp_utils.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_frame_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/server/transport/src/xcp_frame_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_ext_param_default_serial.o : $(MATLAB_ROOT)/toolbox/coder/xcp/src/target/ext_mode/src/xcp_ext_param_default_serial.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mw_mbed_interface.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/stmnucleo/STM32F411RE/src/mw_mbed_interface.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


BufferedSerial.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/BufferedSerial.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mbed_syscalls.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/GCC/mbed_syscalls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


SysTickScheduler.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/SysTickScheduler.c
	$(CC) $(CFLAGS) -o "$@" "$<"


m3m4m4f_multitasking.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/scheduler/src/m3m4m4f_multitasking.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sys_arch.o : $(MATLAB_ROOT)/toolbox/target/shared/armcortexmbase/xcp/src/sys_arch.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xcp_platform_timer_mbed.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/xcp_platform_timer_mbed.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtiostream_serial_mbed.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/mbed/src/rtiostream_serial_mbed.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


