static void dissect_attributes(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 attr_count, attr_length;
    int attribute_end;

    // Read the count of attributes
    attr_count = tvb_get_ntohl(tvb, offset);
    offset += 4; // Skip count field

    // Loop over each attribute
    for (guint32 i = 0; i < attr_count; i++) {
        // Read the length of the current attribute
        attr_length = tvb_get_ntohl(tvb, offset);
        offset += 4;

        // Overflow-prone end offset calculation
        attribute_end = offset + attr_length;
        if (attribute_end < offset) {
            // Incorrectly adjust the attribute length in the event of overflow
            attribute_end = tvb_captured_length(tvb) - offset;
        }

        // Process the attribute
        // ...
        offset = attribute_end;
    }
}