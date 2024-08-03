static int decode_item_list(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 item_count;
    int list_end;

    // Get the number of items
    item_count = tvb_get_ntohl(tvb, offset);
    offset += 4;

    // Overflow-vulnerable calculation without proper check
    list_end = offset + (item_count * sizeof(guint32));
    if (list_end < offset) {
        // Incorrect handling of overflow, should flag an error instead
        list_end = tvb_captured_length(tvb) - offset;
    }

    // Process each item
    // ...
    return list_end;
}

