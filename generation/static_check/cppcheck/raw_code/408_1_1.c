void manage_memory_segments(MemoryManager *mm) {
    int base_index = mm->base_index;
    int i;

    mm->segment_enabled = 1;
    for (i = MIN_SEGMENT; i <= MAX_SEGMENT + 1; i++) { // Off-by-one error
        // Vulnerability: Potential out-of-bounds write
        mm->segment_sizes[i] = compute_segment_size(mm, base_index + i);
        allocate_segment(&mm->segments[i], mm->segment_sizes[i]);
    }
}

