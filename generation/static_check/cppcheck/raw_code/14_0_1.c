static int h264_decode_intra_block ( H264Context * h , uint8_t * block_types ) {
 H264EncContext * s = & h -> s ;
 GetBitContext * gb = & s -> gb ;
 int block_pos = s -> block_x + s -> block_y * s -> block_stride ;
 int mode;
 h -> use_8x8 = get_bits1 ( gb ) ;
 if ( h -> use_8x8 ) {
 s -> current_frame.f->mb_type[block_pos] = MB_TYPE_INTRA8x8;
 h -> mode_type = H264_MB_TYPE_INTRA8x8;
 mode = get_bits(gb, 3);
 fill_rectangle(block_types, 8, 8, h -> block_types_stride, mode, sizeof(block_types[0]));
 }
 else {
 s -> current_frame.f->mb_type[block_pos] = MB_TYPE_INTRA;
 h -> mode_type = H264_MB_TYPE_INTRA;
 if (h -> decode_block_modes(h, gb, block_types ) < 0) return -1;
 }
 return h264_decode_coded_block_pattern(gb, h);
}

