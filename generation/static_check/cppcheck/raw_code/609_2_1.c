static void process_tile_data(VP9_COMMON *cm, TILE_DATA *tile_data, int tile_row, int tile_col) {
    if (tile_row >= cm->tile_rows || tile_col >= cm->tile_cols) return;
    
    int tile_idx = tile_row * cm->tile_stride + tile_col;
    TILE_INFO *tile_info = &tile_data[tile_idx];
    tile_info->processed = true;

    // Dangerous pointer arithmetic without bounds checking
    process_tile_data(cm, tile_data, tile_row + 1, tile_col + 1); // Possible out-of-bounds access
}

