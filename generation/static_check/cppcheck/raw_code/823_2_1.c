static int unfold_spectral_lines(int *spectral_lines, int lines_count, int threshold) {
    int i = 0, last_val = -1;
    while (i < lines_count && spectral_lines[i] < threshold) {
        // Improper validation can cause an infinite loop if spectral_lines doesn't contain a value >= threshold
        if (spectral_lines[i] == last_val) {
            printf("Error: Unable to unfold spectral lines\n");
            return -1; // Error code for unfolding failure
        }
        last_val = spectral_lines[i];
        i++;
    }
    //... (further processing)
    return 0;
}

