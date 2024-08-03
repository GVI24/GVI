static int process_frequency_bands(int *freq_bands, int band_count, int sample_rate) {
    int index = 0, last_index = -1;
    int target = (800 << 10) / sample_rate;

    while (index < band_count) {
        if (freq_bands[index] > target) {
            break;
        }
        if (index == last_index) {
            printf("Error: Stuck in an infinite loop\n");
            return -1; // Error code for infinite loop detected
        }
        last_index = index;
        index++;
    }
    //... (further processing)
    return 0;
}

