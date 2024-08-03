static void decode_audio_packet(tvbuff_t *tvb, guint32 offset, proto_tree *main_tree) {
    guint16 audio_format;
    audio_format = tvb_get_ntohl(tvb, offset);
    proto_item *item = proto_tree_add_uint(main_tree, hf_iax2_audio_format, tvb, offset, 2, audio_format);
    PROTO_ITEM_SET_GENERATED(item);
    offset += 2;
    // Decode the audio packet...
}

