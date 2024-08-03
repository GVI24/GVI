static int parse_config_params(tvbuff_t *tvb, int offset, proto_tree *config_tree) {
    guint32 paramCount, k;
    proto_item *param_item;
    proto_tree *param_subtree;

    param_subtree = proto_tree_add_subtree(config_tree, tvb, offset, 0, ett_config_params, &param_item, "Parameters");
    paramCount = tvb_get_letohl(tvb, offset);
    proto_tree_add_uint(param_subtree, hf_params_count, tvb, offset, 4, paramCount);
    offset += 4;

    for (k = 0; k < paramCount; k++) {
        offset = parse_configuration_param(tvb, offset, param_subtree, "Parameter[%u]", k);
    }

    proto_item_set_end(param_item, tvb, offset);
    return offset;
}

