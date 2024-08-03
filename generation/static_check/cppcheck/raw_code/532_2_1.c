static void rom_load(const char *bios, size_t ram_limit) {
    size_t bios_size;
    uintptr_t bios_base = 0xFE000000, bios_end;
    
    bios_size = load_bios_image(bios, bios_base);
    bios_end = bios_base + bios_size; // Potential overflow here
    
    if (bios_end > ram_limit) {
        fprintf(stderr, "BIOS size exceeds the RAM limit\n");
        exit(EXIT_FAILURE);
    }

    // Continue with hardware initialization using the loaded BIOS
}

