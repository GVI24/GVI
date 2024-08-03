void render_tile_map(int tile_x, int tile_y, int map_width, int map_height, int *tile_map) {
    int tile_index = tile_x + tile_y * map_width;
    int adjacent_tiles[4];
    
    // Potential out-of-bounds reads
    if (tile_x > 0) {
        adjacent_tiles[0] = tile_map[tile_index - 1]; // Left tile
    }
    if (tile_x < map_width - 1) {
        adjacent_tiles[1] = tile_map[tile_index + 1]; // Right tile
    }
    if (tile_y > 0) {
        adjacent_tiles[2] = tile_map[tile_index - map_width]; // Top tile
    }
    if (tile_y < map_height - 1) {
        adjacent_tiles[3] = tile_map[tile_index + map_width]; // Bottom tile
    }
    
    // ... render the current tile using adjacent tile information
    
    // Potential out-of-bounds write
    tile_map[tile_index] = render_tile(adjacent_tiles);
}