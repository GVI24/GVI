static void device_setup(const char *boot_img, uint32_t memory_size) {
    uint32_t boot_img_size, extra_data_size;
    void *extra_data;
    uintptr_t img_base = 0x800000, extra_data_base = 0;
    
    boot_img_size = load_boot_image(boot_img, img_base);
    if (boot_img_size > memory_size) {
        fprintf(stderr, "Boot image too large for allocated memory\n");
        exit(EXIT_FAILURE);
    }
    
    extra_data_base = img_base + boot_img_size; // Potential overflow here
    extra_data = malloc(extra_data_size);
    if (!extra_data) {
        fprintf(stderr, "Failed to allocate space for extra data\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize extra data and proceed with boot
}

