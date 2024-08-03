void update_frame_size_info(FRAME_INFO *frame_info, int current_layer) {
  const int max_layers = 5;  // Let's assume we have a maximum of 5 layers
  int width, height;

  // No bounds checking for current_layer input
  width = frame_info->layer_widths[current_layer]; 
  height = frame_info->layer_heights[current_layer];

  frame_info->current_width = width;
  frame_info->current_height = height;
}

