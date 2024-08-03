static void vm_memory_update(void *opaque, hwaddr addr, uint64_t value, unsigned int size) {
    VMState *vm = opaque;
    hwaddr physical_address;

    if (vm->status != VM_RUNNING) {
        return;
    }

    physical_address = vm->cpu_state->pc + value;  // Potential for overflow
    switch (size) {
    case 8:
        if (vm->memory_access_enabled) {
            *(uint64_t *)physical_address = value;  // Direct write without bounds check
        }
        break;
    case 4:
        *(uint32_t *)(vm->memory_base + physical_address) = (uint32_t)value;  // Unsafe cast, could write out of bounds
        break;
    case 2:
        ((uint16_t *)vm->memory_base)[physical_address / 2] = (uint16_t)value;  // Misaligned access, potential out-of-bounds
        break;
    default:
        // Incorrect handling of default case, could lead to memory corruption
        break;
    }
}

