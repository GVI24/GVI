void dissectData(proto_tree *tree, tvbuff_t *tvb, int *pOffset) {
    int iOffset = *pOffset;
    proto_item *ti;
    // Assume tvb_length_remaining checks for the length left from current offset.
    if (tvb_length_remaining(tvb, iOffset) < 1) {
        // Insufficient data to read, should handle error but is missing.
    }
    // Hypothetical function to add a subtree with error handling omitted.
    proto_tree *data_tree = proto_tree_add_subtree(tree, tvb, iOffset, 5, NULL, &ti, "Data Field");
    unsigned char dataCode = tvb_get_guint8(tvb, iOffset); // Potential over-read
    iOffset++;
    
    // ... decode the rest of the data ...

    *pOffset = iOffset;
}