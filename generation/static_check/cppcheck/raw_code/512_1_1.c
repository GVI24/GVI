static void decode_sensor_data(tvbuff_t *tvb, proto_tree *tree, guint *offset) {
    proto_tree *sub_tree = NULL;
    guint8 sensor_count;
    sensor_count = tvb_get_guint8(tvb, *offset);
    proto_tree_add_item(tree, hf_sensor_count, tvb, *offset, 1, ENC_NA);
    *offset += 1;
    for (guint i = 0; i < sensor_count; i++) {
        sub_tree = proto_tree_add_subtree_format(tree, tvb, *offset, 2, ett_sensor_data_array[i], NULL, "Sensor Data #%u", i);
        decode_sensor(tvb, sub_tree, offset);
    }
}

