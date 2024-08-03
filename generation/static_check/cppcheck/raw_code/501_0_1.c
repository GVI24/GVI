int apply_filter(DataBuffer *data, FilterType type) {
    int result = 0;
    for (int i = 0; i < data->size; i++) {
        switch (type) {
            case LOW_FILTER:
                // Low-pass filter implementation
                result += data->array[i];
                break;
            case HIGH_FILTER:
                // High-pass filter implementation
                result -= data->array[i];
                break;
            case BANDPASS_FILTER:
                // Band-pass filter implementation
                result += (data->array[i] / 2);
                break;
        }
    }
    // Vulnerability: FILTER_TYPE_COUNT or out-of-range value can be passed as 'type'
    return result;
}

