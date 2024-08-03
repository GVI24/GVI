void initialize_rate_control(VP9_COMP *cpi) {
  SVC * const svc = &cpi->svc;
  RATE_CONTROL *const rc = &cpi->rc;
  const int layer = svc->spatial_layer_id;  // potential vulnerability if layer index is out of bounds
  const double framerate = cpi->framerate;
  LAYER_CONTEXT *lc = &svc->layer_context[layer];  // No bounds checking

  lc->target_bandwidth = (int)(framerate * lc->average_bitrate / 1000.0);
  rc->bits_off_target = lc->target_bandwidth;
  rc->buffer_level = rc->starting_buffer_level;
}

