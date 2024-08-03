static void blend_subpicture(OverlayContext *oc, int sp_x, int sp_y) {
    AVFrame *dest = oc->destination;
    int dest_x, dest_y;
    int blend_x = oc->blend_x, blend_y = oc->blend_y;

    // Vulnerable computation of destination coordinates
    dest_x = sp_x + blend_x;
    dest_y = sp_y + blend_y;

    // Lack of bounds checking can cause integer overflow
    blend_overlay(dest, dest_x, dest_y); // Possible out-of-bounds write
}
