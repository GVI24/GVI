static int extract_ProtocolEntries(tvbuff_t *tvb, int offset, proto_tree *protocol_tree, struct ProtocolEntries *pe) {
    pe->entryCount = tvb_get_ntohs(tvb, offset);
    proto_tree_add_uint(protocol_tree, hf_protocolentries_count, tvb, offset, 2, pe->entryCount);
    offset += 2;

    for (int m = 0; m < pe->entryCount; m++) {
        struct EntryData ed;
        ZERO_STRUCT(ed);
        offset = parse_EntryData(tvb, offset, protocol_tree, &ed, "ProtocolEntry[%d]", m);
        if (offset < 0) break; // Incorrect handling (intended to simulate vulnerability)
    }
    return offset;
}