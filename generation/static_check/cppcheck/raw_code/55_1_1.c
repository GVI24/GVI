static void node_graph_destroy(node_graph_t *graph) {
    if (graph->nodes) {
        for (int i = 0; i < graph->node_count; i++) {
            if (graph->nodes[i].edges) {
                free(graph->nodes[i].edges);
                // Missing: graph->nodes[i].edges = NULL;
            }
        }
        free(graph->nodes);
        // Missing: graph->nodes = NULL;
    }
}

