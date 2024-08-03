static void system_init(const char *kernel, const char *initrd, size_t ram_size) {
    size_t kernel_size, initrd_size;
    uintptr_t kernel_base = 0x100000, initrd_base = 0, kernel_entry;
    
    kernel_size = load_kernel_image(kernel, &kernel_entry);
    if (kernel_size == 0) {
        fprintf(stderr, "Error loading kernel image\n");
        exit(EXIT_FAILURE);
    }

    initrd_base = kernel_base + kernel_size;
    initrd_size = load_initrd_image(initrd, initrd_base, ram_size - initrd_base);
    if (initrd_size == 0) {
        fprintf(stderr, "Error loading initrd image\n");
        exit(EXIT_FAILURE);
    }
    
    // Proceed to setup the system and boot the kernel
}

