static int vc1_decode_p_mb_modes ( VC1DecContext * vc , uint8_t * p_modes ) {
 VC1EncContext * es = & vc -> s ;
 GetBitContext * gb = & es -> gb ;
 int mb_index = es -> mb_x + es -> mb_y * es -> mb_stride ;
 vc -> is_p_frame = get_bits1 ( gb ) ;
 if ( vc -> is_p_frame ) {
 es -> current_pic.f->mb_type[mb_index] = MB_TYPE_INTRA;
 int mode = get_bits(gb, 2);
 fill_rectangle(p_modes, es -> mb_width, es -> mb_height, vc -> p_modes_stride, mode, sizeof(p_modes[0]));
 } else {
 es -> current_pic.f->mb_type[mb_index] = MB_TYPE_INTER_P;
 if (vc1_decode_inter_mb_modes(vc, gb, p_modes) < 0) return -1;
 }
 return 0;
}