void write_bitstream(EncoderState *encoder, const char *data, size_t size) {
    // Vulnerability: No check if the encoder or encoder->bitstream is NULL.
    for (size_t i = 0; i < size; i++) {
        write_to_stream(encoder->bitstream, data[i]); // Potential null pointer dereference.
    }

    // Additional functionality...
}

void write_to_stream(Bitstream *stream, char byte) {
    if (stream->position == stream->capacity) {
        // Vulnerability: No check for integer overflow in capacity doubling.
        stream->capacity *= 2;
        stream->data = (char *)realloc(stream->data, stream->capacity);
    }
    stream->data[stream->position++] = byte;
}