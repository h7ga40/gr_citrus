# This file was automagically generated by mbed.org. For more information, 
# see http://mbed.org/handbook/Exporting-to-GCC-ARM-Embedded

###############################################################################
# Boiler-plate

# cross-platform directory manipulation
ifeq ($(shell echo $$OS),$$OS)
    MAKEDIR = if not exist "$(1)" mkdir "$(1)"
    RM = rmdir /S /Q "$(1)"
else
    MAKEDIR = '$(SHELL)' -c "mkdir -p \"$(1)\""
    RM = '$(SHELL)' -c "rm -rf \"$(1)\""
endif

OBJDIR := Debug
# Move to the build directory
ifeq (,$(filter $(OBJDIR),$(notdir $(CURDIR))))
.SUFFIXES:
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKETARGET = '$(MAKE)' --no-print-directory -C $(OBJDIR) -f '$(mkfile_path)' \
		'SRCDIR=$(CURDIR)' $(MAKECMDGOALS)
.PHONY: $(OBJDIR) clean
all:
	+@$(call MAKEDIR,$(OBJDIR))
	+@$(MAKETARGET)
$(OBJDIR): all
Makefile : ;
% :: $(OBJDIR) ; :
clean :
	$(call RM,$(OBJDIR))

else

# trick rules into thinking we are in the root, when we are in the bulid dir
VPATH = ../../micro_speech

# Boiler-plate
###############################################################################
# Project settings

PROJECT := micro_speech


# Project settings
###############################################################################
# Objects and Paths

OBJECTS += lib/PCM.o
OBJECTS += src/arduino/audio_provider.o
OBJECTS += src/arduino/command_responder.o
OBJECTS += src/arduino/main.o
OBJECTS += src/feature_provider.o
OBJECTS += src/main_functions.o
OBJECTS += src/micro_features/micro_features_generator.o
OBJECTS += src/micro_features/micro_model_settings.o
OBJECTS += src/micro_features/no_micro_features_data.o
OBJECTS += src/micro_features/tiny_conv_micro_features_model_data.o
OBJECTS += src/micro_features/yes_micro_features_data.o
OBJECTS += src/recognize_commands.o

INCLUDE_PATHS += -I../../tensorflow-microlite
INCLUDE_PATHS += -I../../tensorflow-microlite/third_party/flatbuffers/include
INCLUDE_PATHS += -I../../tensorflow-microlite/third_party/gemmlowp
INCLUDE_PATHS += -I../../tensorflow-microlite/third_party/kissfft
INCLUDE_PATHS += -I../../tensorflow-microlite/third_party/person_model_grayscale
INCLUDE_PATHS += -I../../wrbb-v2lib-firm/firmware/gr_common
INCLUDE_PATHS += -I../../wrbb-v2lib-firm/firmware/gr_common/core
INCLUDE_PATHS += -I../../micro_speech/lib
INCLUDE_PATHS += -I../../micro_speech/src

MACRO_DEFINES += -DCPPAPP
MACRO_DEFINES += -DNDEBUG
MACRO_DEFINES += -DTF_LITE_MCU_DEBUG_LOG
MACRO_DEFINES += -DTF_LITE_STATIC_MEMORY
MACRO_DEFINES += -DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK
MACRO_DEFINES += -DARDUINOSTL_M_H
MACRO_DEFINES += -DARDUINO=144
MACRO_DEFINES += -DGRSAKURA
MACRO_DEFINES += -D__RX600__
MACRO_DEFINES += -DUSING_UXR
MACRO_DEFINES += -DUSING_WIFI

LIBRARY_PATHS += -L../../tensorflow-microlite/Debug
LIBRARY_PATHS += -L../../wrbb-v2lib-firm/Sakura
LIBRARIES := -ltensorflow-microlite -lwrbb-v2lib-firm
LINKER_SCRIPT ?= ../../asp/target/gr_sketch_gcc/gr_sakura.ld


# Objects and Paths
###############################################################################
# Tools and Flags

AS      = rx-elf-gcc
CC      = rx-elf-gcc
CPP     = rx-elf-g++
AR      = rx-elf-ar
RANLIB  = rx-elf-ranlib
LD      = rx-elf-gcc
ELF2BIN = rx-elf-objcopy

TCINSTALL := $(shell which $(CC))/../../
GCC_VERSION := $(shell $(CC) -dumpversion)

C_FLAGS += -std=gnu11
C_FLAGS += -mcpu=rx600
C_FLAGS += -mlittle-endian-data
C_FLAGS += -m64bit-doubles
C_FLAGS += -misa=v1
C_FLAGS += -Og
C_FLAGS += -g3
C_FLAGS += -fmessage-length=0
C_FLAGS += -ffunction-sections
C_FLAGS += -fdata-sections
C_FLAGS += -fno-builtin
C_FLAGS += -fno-delete-null-pointer-checks
C_FLAGS += -fno-exceptions
C_FLAGS += -fno-rtti
C_FLAGS += -fno-unwind-tables
C_FLAGS += -fomit-frame-pointer
C_FLAGS += -fpermissive
C_FLAGS += -funsigned-char
C_FLAGS += -Wall
C_FLAGS += -Wextra
C_FLAGS += -Wmissing-field-initializers
C_FLAGS += -Wno-unused-parameter
C_FLAGS += -Wno-write-strings
C_FLAGS += -Wshadow
C_FLAGS += -Wsign-compare
C_FLAGS += -Wunused-variable
C_FLAGS += -Wvla
C_FLAGS += -Wstack-usage=256

C_FLAGS := $(C_FLAGS) $(MACRO_DEFINES)

CXX_FLAGS += -std=gnu++11
CXX_FLAGS += -mcpu=rx600
CXX_FLAGS += -mlittle-endian-data
CXX_FLAGS += -m64bit-doubles
CXX_FLAGS += -misa=v1
CXX_FLAGS += -O2
CXX_FLAGS += -g3
CXX_FLAGS += -fmessage-length=0
CXX_FLAGS += -ffunction-sections
CXX_FLAGS += -fdata-sections
CXX_FLAGS += -fno-builtin
CXX_FLAGS += -fno-delete-null-pointer-checks
CXX_FLAGS += -fno-exceptions
CXX_FLAGS += -fno-rtti
CXX_FLAGS += -fno-unwind-tables
CXX_FLAGS += -fomit-frame-pointer
CXX_FLAGS += -fpermissive
CXX_FLAGS += -funsigned-char
CXX_FLAGS += -Wall
CXX_FLAGS += -Wextra
CXX_FLAGS += -Wmissing-field-initializers
CXX_FLAGS += -Wno-unused-parameter
CXX_FLAGS += -Wno-write-strings
CXX_FLAGS += -Wshadow
CXX_FLAGS += -Wsign-compare
CXX_FLAGS += -Wunused-variable
CXX_FLAGS += -Wvla
CXX_FLAGS += -Wstack-usage=256

CXX_FLAGS := $(CXX_FLAGS) $(MACRO_DEFINES)

ASM_FLAGS += -x
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += -mcpu=rx600
ASM_FLAGS += -mlittle-endian-data
ASM_FLAGS += -m64bit-doubles
ASM_FLAGS += -misa=v1
ASM_FLAGS += -Og
ASM_FLAGS += -g3
ASM_FLAGS += -fmessage-length=0
ASM_FLAGS += -ffunction-sections
ASM_FLAGS += -fdata-sections
ASM_FLAGS += -fno-builtin
ASM_FLAGS += -fno-delete-null-pointer-checks
ASM_FLAGS += -fno-exceptions
ASM_FLAGS += -fno-rtti
ASM_FLAGS += -fno-unwind-tables
ASM_FLAGS += -fomit-frame-pointer
ASM_FLAGS += -fpermissive
ASM_FLAGS += -funsigned-char
ASM_FLAGS += -Wall
ASM_FLAGS += -Wextra
ASM_FLAGS += -Wmissing-field-initializers
ASM_FLAGS += -Wno-unused-parameter
ASM_FLAGS += -Wno-write-strings
ASM_FLAGS += -Wshadow
ASM_FLAGS += -Wsign-compare
ASM_FLAGS += -Wunused-variable
ASM_FLAGS += -Wvla
ASM_FLAGS += -Wstack-usage=256

ASM_FLAGS := $(ASM_FLAGS) $(MACRO_DEFINES)

LD_FLAGS += -Wl,--gc-sections
LD_FLAGS += -mcpu=rx600
LD_FLAGS += -m64bit-doubles
LD_FLAGS += -Wl,-Map=$(PROJECT).map,--cref
LD_FLAGS += -L"$(TCINSTALL)rx-elf\lib\64-bit-double"
LD_FLAGS += -L"$(TCINSTALL)lib\gcc\rx-elf/$(GCC_VERSION)\64-bit-double"
LD_FLAGS += -nostartfiles
LD_FLAGS += -Wl,-e_PowerON_Reset

LD_SYS_LIBS += -Wl,--start-group
LD_SYS_LIBS += -lm
LD_SYS_LIBS += -lc
LD_SYS_LIBS += -lgcc
LD_SYS_LIBS += -lstdc++
LD_SYS_LIBS += -lsim
LD_SYS_LIBS += -lnosys
LD_SYS_LIBS += -Wl,--end-group


# Tools and Flags
###############################################################################
# Rules

.PHONY: all lst size


all: $(PROJECT).bin $(PROJECT).hex size


.s.o:
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Assemble: $(notdir $<)"
	@$(AS) -c $(ASM_FLAGS) -o $@ $<

.S.o:
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Assemble: $(notdir $<)"
	@$(AS) -c $(ASM_FLAGS) -o $@ $<

.c.o:
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Compile: $(notdir $<)"
	@$(CC) $(C_FLAGS) $(INCLUDE_PATHS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

.cc.o:
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Compile: $(notdir $<)"
	@$(CPP) $(CXX_FLAGS) $(INCLUDE_PATHS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

.cpp.o:
	+@$(call MAKEDIR,$(dir $@))
	+@echo "Compile: $(notdir $<)"
	@$(CPP) $(CXX_FLAGS) $(INCLUDE_PATHS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"


$(PROJECT).elf: $(OBJECTS) $(SYS_OBJECTS) $(LINKER_SCRIPT) 
	+@echo "$(filter %.o, $^)" > .link_options.txt
	+@echo "link: $(notdir $@)"
	@$(LD) $(LD_FLAGS) -T "$(LINKER_SCRIPT)" $(filter-out %.o, $^) $(LIBRARY_PATHS) --output $@ @.link_options.txt $(LIBRARIES) $(LD_SYS_LIBS)


$(PROJECT).bin: $(PROJECT).elf
	$(ELF2BIN) -O binary $< $@
	+@echo "===== bin file ready to flash: $(OBJDIR)/$@ =====" 

$(PROJECT).hex: $(PROJECT).elf
	$(ELF2BIN) -O ihex $< $@


# Rules
###############################################################################
# Dependencies

DEPS = $(OBJECTS:.o=.d) $(SYS_OBJECTS:.o=.d)
-include $(DEPS)
endif

# Dependencies
###############################################################################
