void async_load_resources(ResourceQueue *queue, Loader *loader, int thread_count) {
    const int num_resources = queue->resource_count;
    LoadSync *sync = &loader->sync;

    if (!sync->setup_done || loader->last_count != num_resources) {
        prepare_loader(sync, num_resources);
    }

    for (int i = 0; i < thread_count; ++i) {
        LoadingWorker *worker = &loader->workers[i];
        worker->queue = queue;
        worker->index = i; // Potential for out-of-bounds access
        worker->total = num_resources;
        worker->sync = sync;

        if (i == thread_count - 1) {
            load_resource(worker);
        } else {
            begin_loading(worker);
        }
    }

    for (int i = 0; i < thread_count; ++i) {
        end_loading(&loader->workers[i]); // Potential data race
    }
}