static int mpeg4_set_intra_blocks ( MPEG4DecContext * m , int * block_codes ) {
 MPEG4EncContext * s = & m -> s ;
 GetBitContext * gb = & s -> gb ;
 int block_index = s -> block_x + s -> block_y * s -> block_stride ;
 m -> is_intra = get_bits1 ( gb ) ;
 if ( m -> is_intra ) {
 s -> current_picture.f->mb_type[block_index] = MB_TYPE_INTRA;
 int code = get_bits(gb, 4);
 fill_rectangle(block_codes, 6, 6, m -> block_codes_stride, code, sizeof(block_codes[0]));
 } else {
 s -> current_picture.f->mb_type[block_index] = MB_TYPE_INTER;
 if (mpeg4_decode_block_pattern(m, gb, block_codes) < 0) return -1;
 }
 return 0;
}

