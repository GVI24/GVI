static void copy_range(const int *source, int *destination, int range_start, int range_length) {
    int i;
    // Vulnerability: No bounds checking on the source or destination based on range_length
    for (i = 0; i < range_length; i++) {
        destination[i] = source[range_start + i]; // Potential out-of-bounds read and write
    }
}