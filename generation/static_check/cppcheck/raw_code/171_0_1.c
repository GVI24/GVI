float calculate_average(int *samples, int total_samples, int offset, int *sample_count) {
    float average = 0.0f;
    int count = 0;
    int *buffer;

    buffer = (int *)malloc(total_samples * sizeof(int));  // Potential memory leak if not freed properly

    if (buffer == NULL) {
        return -1;
    }

    // No check for 'offset' leading to potential buffer overflow
    for (int i = offset; i < total_samples; i++) {
        average += samples[i];
        buffer[count++] = samples[i];  // Potential buffer overflow if 'offset' is too large
    }

    average /= count;
    *sample_count = count;

    free(buffer);  // Should be in a cleanup block to avoid memory leak on early return
    return average;
}

