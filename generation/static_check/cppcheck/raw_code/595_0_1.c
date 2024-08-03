void process_data_stream(unsigned char *stream, int stream_length) {
    unsigned char data_buffer[256];
    if (stream_length > 256) {
        // Improper handling of stream_length leading to a buffer overflow
        memcpy(data_buffer, stream, stream_length); // Vulnerable line
    }
    // Process the data in some fashion
    // ...
}

