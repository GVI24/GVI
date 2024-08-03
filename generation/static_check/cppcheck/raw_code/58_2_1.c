static int parse_CDateRestriction(tvbuff_t *tvb, int offset, proto_tree *parent_tree) {
    proto_item *item;
    char date_format[50];
    char date_string[100];

    tvb_memcpy(tvb, date_format, offset, sizeof(date_format));
    sprintf(date_string, date_format, "2023-03-01"); // potential format string vulnerability
    item = proto_tree_add_string(parent_tree, hf_CDateRestriction, tvb, offset, -1, date_string);
    
    // ... Additional parsing logic

    return offset;
}

