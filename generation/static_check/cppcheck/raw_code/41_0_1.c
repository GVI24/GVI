static int process_audio_metadata(uint8_t *metadata_buf, int metadata_size) {
    if (!metadata_buf) {
        return -1;
    }
    
    // Assuming max metadata size
    const int max_metadata_size = 256;

    // Vulnerability: No metadata_size validation
    uint8_t processed_metadata[max_metadata_size];
    for (int i = 0; i < metadata_size; i++) {
        processed_metadata[i] = metadata_buf[i]; // Potential out-of-bounds read
    }

    // Further processing...
    
    return 0;
}

