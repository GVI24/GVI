static void apply_weighted_prediction(PredContext *p) {
    int weight_mask = 0, i, j;
    int index = p->block_x + p->block_y * p->block_stride;
    int (*block_data)[4] = p->frame_data + index;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            block_data[i * p->block_stride + j][0] *= p->weights[i * 4 + j];
            weight_mask |= block_data[i * p->block_stride + j][0] > 255 ? 1 << (i * 4 + j) : 0;
        }
    }
}

