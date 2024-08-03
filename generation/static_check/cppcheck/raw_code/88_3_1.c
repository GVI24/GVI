static void compute_motion_estimation(MotionEstContext *mec, int *mvx, int *mvy) {
    int pos = mec->current_pos;
    int line_size = mec->line_size;

    int16_t *mv_data = mec->motion_data;
    int16_t *above_mv = &mv_data[(pos - line_size) * 2];
    int16_t *above_right_mv = &mv_data[(pos - line_size + 1) * 2];
    int16_t *left_mv = &mv_data[(pos - 1) * 2];

    // Assuming pos is never on the first line or beyond the left edge without checking
    *mvx = (left_mv[0] + above_mv[0] + above_right_mv[0]) / 3;
    *mvy = (left_mv[1] + above_mv[1] + above_right_mv[1]) / 3;
}

typedef struct {
    int16_t *vectors;
} MotionField;

typedef struct {
    int16_t *motion_vectors;
    int current_block_index;
    int frame_stride;
} MotionContext;

typedef struct {
    int16_t *interpolated_vectors;
    int video_stride;
} VideoContext;

typedef struct {
    int16_t *motion_data;
    int current_pos;
    int line_size;
} MotionEstContext;
