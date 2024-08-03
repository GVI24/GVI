static guint32 parse_video_frame(tvbuff_t *tvb, guint32 offset, packet_info *pinfo, proto_tree *video_tree) {
    guint32 frame_size;
    frame_size = tvb_get_ntohl(tvb, offset);
    if (video_tree) {
        proto_tree_add_uint(video_tree, hf_iax2_video_framesize, tvb, 0, 4, frame_size);
    }
    offset += 4;
    // Parse the video frame content...
    return offset;
}

