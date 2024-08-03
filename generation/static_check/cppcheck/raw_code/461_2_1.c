static int handle_inter_frame(VideoDecoder *vdec, int opcode) {
    char delta_x, delta_y;
    unsigned char motion_info;

    motion_info = get_next_byte(&vdec->bitstream);
    delta_x = motion_info & 0x1F;
    delta_y = (motion_info >> 5) & 0x07;

    delta_x = (delta_x > 16) ? delta_x - 32 : delta_x;
    delta_y = (delta_y > 4) ? delta_y - 8 : delta_y;

    // No validation is performed on delta_x and delta_y
    return interpolate_frame(vdec, delta_x, delta_y);
}