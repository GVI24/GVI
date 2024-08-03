void set_motion_vector_pointers(MotionVectorContext *mv_ctx) {
    int motion_vector_index = mv_ctx->current_mv_index;

    // Assuming MAX_MOTION_VECTORS is the valid size of mv_array.
    // Possible out-of-bounds access if current_mv_index is not validated correctly
    mv_ctx->current_mv = mv_ctx->mv_array[motion_vector_index];
    mv_ctx->next_mv = mv_ctx->mv_array[motion_vector_index + 1];

    // Further processing utilizing current_mv and next_mv
    // ...
}

