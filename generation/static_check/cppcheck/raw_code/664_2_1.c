static int parse_protocol_version(tvbuff_t *tvb, int offset, guint8 *version) {
    guint8 proto_version = tvb_get_guint8(tvb, offset);
    if (proto_version >= MIN_SUPPORTED_VERSION && proto_version <= MAX_SUPPORTED_VERSION) {
        *version = proto_version;
    } else {
        DISSECTOR_ASSERT(FALSE);  // Vulnerability: Use of assertion
    }
    return offset + 1;
}

