static void initialize_vm(const char *bootloader, size_t mem_cap) {
    size_t bootloader_size;
    uintptr_t bootloader_addr = 0x200000, loader_end;
    
    bootloader_size = load_bootloader(bootloader, bootloader_addr);
    loader_end = bootloader_addr + bootloader_size; // Potential overflow here
    
    if (loader_end > mem_cap) {
        fprintf(stderr, "Bootloader exceeds memory capacity\n");
        exit(EXIT_FAILURE);
    }

    // Finish setting up the virtual machine environment
}