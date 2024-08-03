int parse_NetworkMetrics(tvbuff_t *tvb, int offset, proto_tree *metrics_tree) {
    proto_item *mi;
    proto_tree *tree;
    guint32 metricCount;
    tree = proto_tree_add_subtree(metrics_tree, tvb, offset, 0, ett_NetworkMetrics, &mi, "Network Metrics");
    metricCount = tvb_get_ntohl(tvb, offset);
    proto_tree_add_uint(tree, hf_network_metrics_count, tvb, offset, 4, metricCount);
    offset += 4;
    for (unsigned int j = 0; j < metricCount; j++) {
        // Vulnerability: the value of metricCount controls loop bounds without check
        offset = parse_MetricValue(tvb, offset, tree, "Metric[%u]", j);
    }
    proto_item_set_end(mi, tvb, offset);
    return offset;
}

