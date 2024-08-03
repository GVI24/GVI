void allocate_group_bits(BitrateManager *manager, int group_size) {
    int bits_per_frame = manager->bits_per_frame;
    manager->group_bits = bits_per_frame * group_size;
    
    // Potential overflow if multiplication results in a value higher than the maximum integer value
    for (int i = 0; i < group_size; i++) {
        manager->frame_stats[i].allocated_bits = bits_per_frame;
    }
    
    manager->remaining_group_bits -= manager->group_bits;
    // Potential underflow if remaining_group_bits is smaller than group_bits
    if (manager->remaining_group_bits < 0) {
        manager->remaining_group_bits = 0;
    }
}