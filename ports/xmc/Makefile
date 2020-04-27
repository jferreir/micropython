# Select the board to build for: if not given on the command line,
# then default to RELAXKIT_XMC47.
BOARD ?= RELAXKIT_XMC47

# If the build directory is not given, make it reflect the board name.
BUILD ?= build-$(BOARD)

BOARD_DIR ?= boards/$(BOARD)
ifeq ($(wildcard $(BOARD_DIR)/.),)
$(error Invalid BOARD specified: $(BOARD_DIR))
endif

CROSS_COMPILE ?= arm-none-eabi-

ifeq ($(wildcard $(BOARD_DIR)/.),)
$(error Invalid BOARD specified: $(BOARD_DIR))
endif

include ../../py/mkenv.mk

# Qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h
QSTR_GLOBAL_DEPENDENCIES = $(BOARD_DIR)/mpconfigboard.h

# Include py core make definitions
include $(TOP)/py/py.mk
include $(BOARD_DIR)/mpconfigboard.mk

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)
INC += -Iboards
INC += -I$(BOARD_DIR)
INC += -I$(TOP)/lib/xmclib/CMSIS/Include
INC += -I$(TOP)/lib/xmclib/CMSIS/Infineon/$(MCU_SERIES)_series/Include
INC += -I$(TOP)/lib/xmclib/driver/inc
INC += -I$(TOP)/lib/xmclib/ThirdPartyLibraries/ringbuff/ringbuff/src/include

LD=$(CC)

CFLAGS_MCU_XMC1 = -mcpu=cortex-m0
CFLAGS_MCU_XMC4 = -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS = $(INC) -Wall -Werror -std=c99 -mthumb $(CFLAGS_MCU_$(MCU_FAMILY)) -fno-builtin -fdata-sections -ffunction-sections -fsingle-precision-constant -Wdouble-promotion
CFLAGS += -D$(MCU_DEVICE)_$(MCU_PACKAGE)x$(MCU_FLASH)
LDFLAGS = $(addprefix -T,$(LD_FILES)) -nostartfiles -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs -Wl,-Map,"$@.map" -mthumb $(CFLAGS_MCU_$(MCU_FAMILY))
LIBS = -lm

# Tune for Debugging or Optimization
ifeq ($(DEBUG),1)
CFLAGS += -Og -g
else
CFLAGS += -Os -DNDEBUG -flto
LDFLAGS += -flto
endif

SRC_C = \
	lib/xmclib/driver/src/xmc1_gpio.c \
	lib/xmclib/driver/src/xmc1_flash.c \
	lib/xmclib/driver/src/xmc1_eru.c \
	lib/xmclib/driver/src/xmc_bccu.c \
	lib/xmclib/driver/src/xmc_acmp.c \
	lib/xmclib/driver/src/xmc4_scu.c \
	lib/xmclib/driver/src/xmc4_rtc.c \
	lib/xmclib/driver/src/xmc4_gpio.c \
	lib/xmclib/driver/src/xmc4_flash.c \
	lib/xmclib/driver/src/xmc4_eru.c \
	lib/xmclib/driver/src/xmc1_scu.c \
	lib/xmclib/driver/src/xmc1_rtc.c \
	lib/xmclib/driver/src/xmc_ebu.c \
	lib/xmclib/driver/src/xmc_dsd.c \
	lib/xmclib/driver/src/xmc_dma.c \
	lib/xmclib/driver/src/xmc_dac.c \
	lib/xmclib/driver/src/xmc_common.c \
	lib/xmclib/driver/src/xmc_ccu8.c \
	lib/xmclib/driver/src/xmc_ccu4.c \
	lib/xmclib/driver/src/xmc_can.c \
	lib/xmclib/driver/src/xmc_gpio.c \
	lib/xmclib/driver/src/xmc_fce.c \
	lib/xmclib/driver/src/xmc_eth_phy_ksz8081rnb.c \
	lib/xmclib/driver/src/xmc_eth_phy_ksz8031rnl.c \
	lib/xmclib/driver/src/xmc_eth_phy_dp83848.c \
	lib/xmclib/driver/src/xmc_eth_mac.c \
	lib/xmclib/driver/src/xmc_eru.c \
	lib/xmclib/driver/src/xmc_ecat.c \
	lib/xmclib/driver/src/xmc_rtc.c \
	lib/xmclib/driver/src/xmc_prng.c \
	lib/xmclib/driver/src/xmc_posif.c \
	lib/xmclib/driver/src/xmc_pau.c \
	lib/xmclib/driver/src/xmc_math.c \
	lib/xmclib/driver/src/xmc_ledts.c \
	lib/xmclib/driver/src/xmc_i2s.c \
	lib/xmclib/driver/src/xmc_i2c.c \
	lib/xmclib/driver/src/xmc_hrpwm.c \
	lib/xmclib/driver/src/xmc_wdt.c \
	lib/xmclib/driver/src/xmc_vadc.c \
	lib/xmclib/driver/src/xmc_usic.c \
	lib/xmclib/driver/src/xmc_usbh.c \
	lib/xmclib/driver/src/xmc_usbd.c \
	lib/xmclib/driver/src/xmc_uart.c \
	lib/xmclib/driver/src/xmc_spi.c \
	lib/xmclib/driver/src/xmc_sdmmc.c \
	lib/xmclib/CMSIS/Infineon/$(MCU_SERIES)_series/Source/system_$(MCU_SERIES).c \
	lib/xmclib/ThirdPartyLibraries/Newlib/syscalls.c \
	lib/xmclib/ThirdPartyLibraries/ringbuff/ringbuff/src/ringbuff/ringbuff.c \
	lib/libc/string0.c \
	lib/libm/ef_sqrt.c \
	lib/libm/fmodf.c \
	lib/libm/math.c \
	lib/libm/nearbyintf.c \
	lib/mp-readline/readline.c \
	lib/utils/printf.c \
	lib/utils/pyexec.c \
	lib/utils/stdout_helpers.c \
	main.c \
	mphalport.c \
	help.c \
	modules/machine/modmachine.c \
	modules/machine/machine_pin.c \
	modules/utime/modutime.c \
	$(BOARD_DIR)/board.c \


ifeq ($(MCU_FAMILY),XMC1)
SRC_s = lib/utils/gchelper_m0.s
else
SRC_s = lib/utils/gchelper_m3.s
endif

SRC_S = lib/xmclib/CMSIS/Infineon/$(MCU_SERIES)_series/Source/GCC/startup_$(MCU_SERIES).S

# List of sources for qstr extraction
SRC_QSTR += \
	modules/machine/modmachine.c \
	modules/machine/machine_pin.c \
    modules/utime/modutime.c \
	$(BOARD_DIR)/board.c \

OBJ += $(PY_O)
OBJ += $(addprefix $(BUILD)/, $(SRC_C:.c=.o))
OBJ += $(addprefix $(BUILD)/, $(SRC_s:.s=.o))
OBJ += $(addprefix $(BUILD)/, $(SRC_S:.S=.o))

LD_FILES = $(TOP)/lib/xmclib/CMSIS/Infineon/$(MCU_SERIES)_series/Source/GCC/$(MCU_DEVICE)x$(MCU_FLASH).ld

all: $(BUILD)/firmware.elf

$(BUILD)/firmware.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(Q)$(SIZE) $@

$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
	$(Q)$(OBJCOPY) -O binary -j .isr_vector -j .text -j .data $^ $(BUILD)/firmware.bin

include $(TOP)/py/mkrules.mk
