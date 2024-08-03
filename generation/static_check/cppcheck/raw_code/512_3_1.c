static void analyze_thermostat_data(tvbuff_t *tvb, proto_tree *tree, guint *offset) {
    proto_tree *sub_tree = NULL;
    guint8 zone_count;
    zone_count = tvb_get_guint8(tvb, *offset);
    proto_tree_add_item(tree, hf_thermostat_zone_count, tvb, *offset, 1, ENC_NA);
    *offset += 1;
    for (guint i = 0; i < zone_count; i++) {
        sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 4, ett_thermostat_zones[i], NULL, "Thermostat Zone #%u", i);
        analyze_zone(tvb, sub_tree, offset);
    }
}