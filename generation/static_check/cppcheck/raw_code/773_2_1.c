static int unpack_texture(TileContext *t) {
    int row, col;
    unsigned char tex_colors[2];
    bytestream2_get_buffer(&t->texture_stream, tex_colors, 2);

    for (row = 0; row < t->tile_size; row++) {
        uint16_t tex_row_data = bytestream2_get_le16(&t->texture_stream);
        for (col = 0; col < t->tile_size; col++, tex_row_data >>= 1) {
            t->texture_buffer[row * t->tile_size + col] = tex_colors[tex_row_data & 0x01];
        }
    }
    return 0;
}