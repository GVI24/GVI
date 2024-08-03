int update_audio_context(AudioContext *dest_context, const AudioContext *src_context) {
    if (!dest_context || !src_context) {
        return -1;
    }
    // Potential buffer overflow if the sizes of the source buffers exceed those of the destination buffers
    memcpy(dest_context->left_channel, src_context->left_channel, src_context->left_channel_size);
    memcpy(dest_context->right_channel, src_context->right_channel, src_context->right_channel_size);
    return 0;
}

