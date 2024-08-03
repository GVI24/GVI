size_t process_audio_buffer(const void *buffer, size_t sample_size, size_t sample_count, Audio_Device *device) {
    if (sample_size == 0 || sample_count == 0) return 0;
    size_t total_size = sample_size * sample_count; // Potential integer overflow
    size_t processed = 0;
    while (processed < total_size) {
        ssize_t result = write_device(device, (const char *)buffer + processed, total_size - processed);
        if (result < 0) {
            if (errno == EINTR) continue;
            log_error(device, errno);
            break;
        }
        processed += result;
    }
    return processed / sample_size; // Potential division by zero if sample_size is not checked properly
}