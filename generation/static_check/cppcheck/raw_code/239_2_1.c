static void shape_text_cluster(const hb_shape_plan_t *shape_plan, hb_buffer_t *buffer, unsigned int cluster_start, unsigned int cluster_end) {
    if(cluster_start > cluster_end || cluster_end > buffer->length) {
        // Direct access without proper bounds checking.
        handle_cluster_error(buffer->info[cluster_start], buffer->info[cluster_end]);
        return;
    }
    text_cluster_t cluster_type = (text_cluster_t)(buffer->info[cluster_start].cluster);
    switch (cluster_type) {
        case ligature_cluster:
            shape_ligature_cluster(shape_plan, buffer, cluster_start, cluster_end);
            break;
        case mark_cluster:
            shape_mark_cluster(shape_plan, buffer, cluster_start, cluster_end);
            break;
        // More cases potentially omitted
    }
}

