void adjust_frame_rate_control(FrameRateController *ctrl, int num_of_layers) {
    int i;
    for (i = 0; i < num_of_layers; ++i) {
        ctrl->layer_thresholds[i] = calculate_threshold(ctrl, i);
    }
    ctrl->layer_thresholds[i] += ctrl->base_threshold; // out-of-bounds after the loop
    ctrl->layer_thresholds[LAYER_SYNC] = INT_MAX;
    if (ctrl->sync_mode != FRAME_SYNC) {
        ctrl->layer_thresholds[LAYER_SYNC] = compute_sync_threshold(ctrl);
    }
}