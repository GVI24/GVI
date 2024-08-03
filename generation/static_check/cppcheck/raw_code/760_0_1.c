void set_motion_vectors(MotionVectorContext *mv_ctx) {
    int index, ref;
    for (ref = 0; ref < mv_ctx->num_refs; ref++) {
        for (index = 0; index < mv_ctx->mv_count[ref]; index++) {
            MotionVector *mv = &mv_ctx->mv_array[ref][index];
            MotionVector *predictor = &mv_ctx->mv_predictors[ref][32 + index];
            *predictor = *mv;
            predictor->x += mv_ctx->delta_x;
            predictor->y += mv_ctx->delta_y;
        }
    }
}

