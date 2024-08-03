static int parse_CProtocolMessage(tvbuff_t *tvb, int offset, proto_tree *tree, const char *label_fmt, ...) {
    proto_item *pi;
    va_list ap;
    char label[100];

    va_start(ap, label_fmt);
    vsnprintf(label, sizeof(label), label_fmt, ap);
    va_end(ap);

    pi = proto_tree_add_none_format(tree, hf_CProtocolMessage_item, tvb, offset, -1, "%s", label);
    
    // Here, more parsing depending on the protocol message structure should follow...

    return offset;
}
