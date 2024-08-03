void calculate_bandwidth_allocation(VIDEO_COMPRESSOR *vc, int layer_id) {
  LAYER_CONTEXT *layer_ctx;
  int frame_count;
  double duration;

  layer_ctx = &vc->layer_context[layer_id];  // No verification for array bounds of layer_context
  frame_count = layer_ctx->frame_count;
  duration = layer_ctx->frame_duration;

  // No check for division by zero if duration is 0
  layer_ctx->bandwidth_allocation = frame_count / duration * layer_ctx->target_bandwidth;
}