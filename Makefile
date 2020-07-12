CROSS = i686-elf
CFLAGS = -O2 -Isrc -mgeneral-regs-only -Wall -Wextra -ffreestanding -g
AS = nasm
ASFLAGS = -f elf32
BUILD_DIR = build
SRC_DIR = src

all: capos.elf

clean:
	rm -rf $(BUILD_DIR)/*.o

iso:
	mkdir -p iso/boot/grub/
	cp build/capos.elf iso/boot/capos.elf
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o capos.iso iso/
	rm -rf iso/

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/asm/%.S
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/c/%.c
	mkdir -p $(@D)
	$(CROSS)-gcc $(CFLAGS) -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/c/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/asm/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/c/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/asm/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

capos.elf: $(SRC_DIR)/linker.ld $(OBJ_FILES)
	$(CROSS)-ld -Ttext 0x0 -T $(SRC_DIR)/linker.ld -o $(BUILD_DIR)/capos.elf  $(OBJ_FILES)
	$(CROSS)-objcopy --only-keep-debug $(BUILD_DIR)/capos.elf $(BUILD_DIR)/capos.sym
	$(CROSS)-objcopy --strip-debug $(BUILD_DIR)/capos.elf
