void video_process_frame(VideoContext *vid_ctx) {
    int qp;
    int pos = vid_ctx->mb_y * vid_ctx->mb_line + vid_ctx->mb_x;
    uint8_t *frame_y = vid_ctx->planes[0];
    uint8_t *frame_u = vid_ctx->planes[1];
    uint8_t *frame_v = vid_ctx->planes[2];

    qp = vid_ctx->current_qp;
    vid_ctx->filter_ops.vert_filter(frame_y + vid_ctx->width, vid_ctx->width, qp);
    vid_ctx->filter_ops.vert_filter(frame_y + vid_ctx->width + vid_ctx->block_size, vid_ctx->width, qp);
    
    if (vid_ctx->mb_y > 0) {
        int qp_above = vid_ctx->qp_map[pos - vid_ctx->mb_line];
        if (qp_above) {
            // This could potentially read/write outside the allocated frame buffers if mb_y is 1
            vid_ctx->filter_ops.horiz_filter(frame_y - (vid_ctx->block_size * vid_ctx->width), vid_ctx->width, qp_above);
            vid_ctx->filter_ops.horiz_filter(frame_u - (vid_ctx->block_size * (vid_ctx->width / 2)), vid_ctx->width / 2, qp_above);
            vid_ctx->filter_ops.horiz_filter(frame_v - (vid_ctx->block_size * (vid_ctx->width / 2)), vid_ctx->width / 2, qp_above);
        }
    }

    if (vid_ctx->mb_x > 0) {
        int qp_left = vid_ctx->qp_map[pos - 1];
        vid_ctx->filter_ops.vert_filter(frame_y - 1, vid_ctx->width, qp_left);
        vid_ctx->filter_ops.vert_filter(frame_u - (vid_ctx->width / 2), vid_ctx->width / 2, qp_left);
        vid_ctx->filter_ops.vert_filter(frame_v - (vid_ctx->width / 2), vid_ctx->width / 2, qp_left);
    }
}
