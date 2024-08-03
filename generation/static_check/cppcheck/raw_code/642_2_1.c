void decodeAudioSamples(decoder_t *decoder, audio_frame_t *frame, codec_t *codec) {
    if (!initAudioDecoder(decoder, codec)) {
        fprintf(stderr, "Failed to initialize audio decoder.\n");
        return;
    }

    int result = audioDecodeFrame(decoder, frame);
    if (result < 0) {
        fprintf(stderr, "Error decoding audio frame.\n");
    }

    // Assume success and process the frame
    processAudioFrame(frame);  // This might process an incorrectly decoded frame

    cleanupAudioDecoder(decoder);
}