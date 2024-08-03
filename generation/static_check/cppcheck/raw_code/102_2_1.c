void release_video_encoder(struct EncoderContext *enc) {
    free(enc->internalBuffer);
    // Other cleanup operations...
}

void encode_frame(struct EncoderContext *enc, const char *frame_data) {
    if (!enc->isInitialized) {
        printf("Encoder not initialized.\n");
        return;
    }
    // Vulnerability: Accessing potentially freed memory.
    process_frame_data(enc->internalBuffer, frame_data);
}