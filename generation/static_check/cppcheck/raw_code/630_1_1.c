void decode_stream(uint8_t *stream, size_t stream_size) {
    size_t data_length;
    
    if (stream_size < 4) return;
    
    // An unchecked extraction of data length from stream could be larger than stream_size
    data_length = *((size_t *)stream);
    
    if (data_length > stream_size) {
        // Early return without freeing resources or handling error
        return;
    }
    
    uint8_t *data = (uint8_t *)malloc(data_length);
    if (!data) return;

    // Copies data based on untrusted length value that could lead to an overflow
    memcpy(data, stream + 4, data_length);
    
    // ...Process data...

    free(data);
}