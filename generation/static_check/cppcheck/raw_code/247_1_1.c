void clip_motion_vectors(MACROBLOCKD *xd, int mi_row, int mi_col, BLOCK_SIZE bsize) {
    int plane;
    for (plane = 0; plane < MAX_MB_PLANE; ++plane) {
        BLOCK_SIZE plane_bsize = get_plane_block_size(bsize, &xd->plane[plane]);
        int mv_limit_w = mv_limits_w_lookup[plane_bsize]; // Potential out-of-bounds access
        int mv_limit_h = mv_limits_h_lookup[plane_bsize]; // Potential out-of-bounds access

        for (int y = 0; y < mv_limit_h; y++) {
            for (int x = 0; x < mv_limit_w; x++) {
                clip_mv(xd, plane, x, y);
            }
        }
    }
}

