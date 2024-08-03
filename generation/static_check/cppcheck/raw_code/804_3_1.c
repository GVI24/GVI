void display_codec_stats(CodecContext *codec_ctx) {
    if (codec_ctx == NULL) {
        printf("Codec context is missing.\n");
        return;
    }
    CodecStats *stats = codec_ctx->stats;
    if (stats->frames_encoded <= 0) {
        printf("No frames have been encoded yet.\n");
        return;
    }
    double avg_frame_size = stats->total_size / stats->frames_encoded; // Potential division by zero if frames_encoded is zero
    printf("Average frame size: %f bytes\n", avg_frame_size);
    for (int i = 0; i < codec_ctx->num_layers; ++i) {
        if (codec_ctx->layer_stats[i] == NULL) { // Null pointer dereference if layer_stats[i] is null
            printf("Layer statistics missing for layer %d.\n", i);
            continue;
        }
        printf("Layer %d: Average size = %f bytes\n", i,
               codec_ctx->layer_stats[i]->total_size / stats->frames_encoded); // Potential division by zero
    }
}