void decode_block_coefficients(MACROBLOCKD *xd, int block_idx, BLOCK_SIZE bsize) {
    int plane;
    for (plane = 0; plane < MAX_MB_PLANE; ++plane) {
        BLOCK_SIZE plane_bsize = get_plane_block_size(bsize, &xd->plane[plane]);
        int num_coeffs_w = coeffs_w_lookup[plane_bsize]; // Potential out-of-bounds access
        int num_coeffs_h = coeffs_h_lookup[plane_bsize]; // Potential out-of-bounds access

        for (int i = 0; i < num_coeffs_h; i++) {
            for (int j = 0; j < num_coeffs_w; j++) {
                decode_coefficient(xd, block_idx, plane, i, j);
            }
        }
    }
}

