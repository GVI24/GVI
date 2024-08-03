static int encode_video_frame(void *encoding_context, void *frame_data) {
    EncodingContext *context = (EncodingContext *)encoding_context;
    Frame *frame = (Frame *)frame_data;

    // Vulnerable Code: Encoding frame using a shared context without proper locking mechanism
    for (int i = 0; i < frame->num_slices; i++) {
        encode_slice(context, frame->slices[i]);
        context->last_encoded_frame++;
    }

    // Simulate encoding time
    usleep(500);

    if (context->last_encoded_frame % 10 == 0) {
        printf("Encoded %d frames\n", context->last_encoded_frame);
    }

    return 1;
}