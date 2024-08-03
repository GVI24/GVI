static void save_block_modes(MACROBLOCKD *xd, BLOCK_SIZE bsize, MODE_INFO *mi, int modes[4][4], BLOCK_SIZE sub_blocks[4][4]) {
    for (int row = 0; row < bsize; row++) {
        for (int col = 0; col < bsize; col++) {
            // Vulnerable: No bounds checking for 'modes' and 'sub_blocks' matrices based on 'bsize'
            xd->mi[row * xd->mi_stride + col].src_mi->sb_type = sub_blocks[row][col];
            xd->mi[row * xd->mi_stride + col].src_mi->mode = modes[row][col];
        }
    }
}
