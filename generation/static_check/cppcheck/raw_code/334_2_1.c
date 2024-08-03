static int handle_new_sequence(SequenceParams *seq_params, BufferReader *reader) {
    int result = get_sequence_header(seq_params, reader);
    // Vulnerability: Missing error handling if sequence header cannot be read.
    if (result < 0) {
        printf("Error reading sequence header\n");
        return result;
    }
    // Vulnerability: No check if the sequence buffer allocation fails.
    seq_params->buffer = malloc(seq_params->buffer_size);
    if (seq_params->buffer == NULL) {
        log_error("Failed to allocate sequence buffer.\n");
        return -1;
    }
    return 0;
}

