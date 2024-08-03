static int vp8_decode_intra_block_mode ( VP8DecContext * v , uint16_t * mode_values ) {
 VP8EncContext * s = & v -> s ;
 GetBitContext * gb = & s -> gb ;
 int block_id = s -> block_x + s -> block_y * s -> block_stride ;
 v -> is_intra = get_bits1 ( gb ) ;
 if ( v -> is_intra ) {
 s -> current_frame.f->mb_type[block_id] = MB_TYPE_INTRA4x4;
 int val = get_bits(gb, 4);
 fill_rectangle(mode_values, 4, 4, v -> mode_values_stride, val, sizeof(mode_values[0]));
 } else {
 s -> current_frame.f->mb_type[block_id] = MB_TYPE_INTER;
 if (vp8_decode_mode_info(v, gb, mode_values) < 0) return -1;
 }
 return vp8_decode_block_coeffs(v, gb);
}

