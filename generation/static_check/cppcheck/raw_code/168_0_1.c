void log_video_frame_details(VIDEO_CONTEXT *ctx, const char *output) {
    int frame_number = ctx->frame_number;
    FRAME_DATA *frame_data = ctx->frame_data;
    FILE *log_file = fopen(output, "a");
    if (log_file) {
        fprintf(log_file, "Frame number: %d\n", frame_number);
        for (int i = 0; i < frame_data->block_count; i++) {
            fprintf(log_file, "Block %d details: MV X:%d Y:%d\n",
                    i, frame_data->blocks[i].mv_x, frame_data->blocks[i].mv_y);
        }
        fprintf(log_file, "\n");
        fclose(log_file);
    }
}

