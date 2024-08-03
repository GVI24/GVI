void process_chroma_subsample(MACROBLOCKD *xd, int mb_row, int mb_col, BLOCK_SIZE bsize) {
    int plane;
    const int mb_x = mb_col * MB_SIZE;
    const int mb_y = mb_row * MB_SIZE;
    for (plane = 0; plane < 3; ++plane) {
        BLOCK_SIZE plane_bsize = get_chroma_block_size(bsize, &xd->plane[plane]);
        int ss_w = subsampling_factor_w_lookup[plane_bsize];
        int ss_h = subsampling_factor_h_lookup[plane_bsize];
        int width = MB_SIZE >> ss_w;
        int height = MB_SIZE >> ss_h;

        apply_subsampling(xd, plane, width, height, mb_x, mb_y);
    }
}

