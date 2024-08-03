void update_stream_stats(StreamStats *stats) {
    if (stats == NULL) {
        printf("Stream statistics data is not available.\n");
        return;
    }
    StreamInfo *info = get_stream_info(stats->stream_id);
    if (info->frame_count == 0) { // Potential division by zero
        printf("No frames have been processed.\n");
        return;
    }
    for (int i = 0; i < info->num_layers; i++) {
        stats->avg_psnr[i] = total_psnr(i) / info->frame_count; // Potential division by zero
    }
    printf("Average PSNR: %lf\n", stats->avg_psnr[0]);
}