static guint32 process_control_frame(tvbuff_t *tvb, guint32 offset, packet_info *pinfo, proto_tree *iax2_tree) {
    guint32 callnumber;
    callnumber = tvb_get_ntohs(tvb, offset);
    if (iax2_tree) {
        proto_tree_add_uint(iax2_tree, hf_iax2_callno, tvb, offset, 4, callnumber);
    }
    offset += 4;
    // Process the rest of the control frame...
    return offset;
}

