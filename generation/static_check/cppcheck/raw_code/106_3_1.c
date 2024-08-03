static void configure_tile_info(TILE_INFO *tile_info, TILE_CONFIG *config, int num_tiles) {
    for (int i = 0; i < num_tiles; i++) {
        // No bounds checking on the array access of 'config->tile_data'
        tile_info->tiles[i].width = config->tile_data[i].width;
        tile_info->tiles[i].height = config->tile_data[i].height;
    }
}