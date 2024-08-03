stream_data * get_stream_buffer(stream_manager * mgr, int stream_id) {
    stream_data * s_data;
    s_data = stream_manager_find(mgr, stream_id);
    if (s_data != NULL)
        return s_data; // Potential use-after-free if s_data is disposed elsewhere.

    s_data = malloc(sizeof(stream_data));
    s_data->ref_count = 1;
    s_data->id = stream_id;
    s_data->buffer = init_stream_buffer(stream_id);
    stream_manager_add(mgr, stream_id, s_data);
    
    return s_data;
}