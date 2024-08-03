static int filter_graph_init(filter_graph_t *graph) {
    int status = FILTER_GRAPH_SUCCESS;
    if (graph->impl == NULL) {
        filter_impl_t *impl = malloc(sizeof(*impl));
        if (impl == NULL) return FILTER_GRAPH_MEM_ERROR;

        graph->impl = impl;
        impl->filter_chain = default_filter_chain();

        if (!init_filters(impl->filter_chain)) {
            status = FILTER_GRAPH_INIT_ERROR;
            // Memory leak: 'impl' is not freed when filter initialization fails
        } else {
            impl->graph_context = create_graph_context(impl->filter_chain);
            if (impl->graph_context == NULL) {
                status = FILTER_GRAPH_MEM_ERROR;
                // Memory leak: 'impl' is not freed if 'graph_context' creation fails
            }
        }
    }
    return status;
}