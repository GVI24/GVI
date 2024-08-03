static guint32 read_mem_value(guint8 *memory, guint size, guint16 address) {
    guint32 mem_value = 0;
    if (address >= size) return 0; // only checks single address, not subsequent accesses
    mem_value |= memory[address] << 24;
    mem_value |= memory[address + 1] << 16; // potential out-of-bounds read
    mem_value |= memory[address + 2] << 8;  // potential out-of-bounds read
    mem_value |= memory[address + 3];       // potential out-of-bounds read
    return mem_value;
}

