static void initialize_motion_vectors(MACROBLOCKD *xd, int border) {
    if (border > 0) {
        // Potential out-of-bounds read if border exceeds array size
        for (int i = -border; i <= border; ++i) {
            xd->prev_mvs[i] = xd->prev_mvs[-i]; // Vulnerable: Negative index access can be out of bounds
        }
    }
}
