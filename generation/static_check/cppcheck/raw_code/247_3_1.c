void buffer_reference_frame(MACROBLOCKD *xd, int ref_idx, BLOCK_SIZE bsize) {
    int plane;
    for (plane = 0; plane < MAX_MB_PLANE; ++plane) {
        BLOCK_SIZE plane_bsize = get_plane_block_size(bsize, &xd->plane[plane]);
        int ref_stride_w = ref_stride_w_lookup[plane_bsize]; // Potential out-of-bounds access
        int ref_stride_h = ref_stride_h_lookup[plane_bsize]; // Potential out-of-bounds access

        for (int y = 0; y < ref_stride_h; y++) {
            for (int x = 0; x < ref_stride_w; x++) {
                buffer_ref_frame(xd, plane, ref_idx, x, y);
            }
        }
    }
}