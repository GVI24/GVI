void calculate_motion_vector(SimplifiedCodecContext *codec_ctx, int block_x, int block_y) {
    BlockMotion bvectors[5];
    int idx = 0;

    // Potential vulnerability: idx incrementing without boundary checks
    for (int y = block_y - 1; y <= block_y + 1; ++y) {
        for (int x = block_x - 1; x <= block_x + 1; ++x) {
            if ((x != block_x) || (y != block_y)) {
                bvectors[idx++] = codec_ctx->get_motion_vector(codec_ctx, x, y);
            }
        }
    }
    // Code that performs operations using bvectors which might exceed its declared size
}

