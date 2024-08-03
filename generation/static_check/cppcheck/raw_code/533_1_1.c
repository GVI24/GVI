void parallel_compress_files(FileList *files, Compressor *comp, int num_threads) {
    const int total_files = files->count;
    Sync *sync = &comp->sync;

    if (!sync->is_initialized) {
        setup_sync(sync, total_files);
    }

    for (int i = 0; i < num_threads; ++i) {
        Worker *worker = &comp->workers[i];
        worker->file_list = files;
        worker->start_file_index = i;
        worker->total_files = total_files;
        worker->sync = sync;

        if (i == num_threads - 1) {
            compress_files(worker);
        } else {
            start_worker(worker);
        }
    }

    for (int i = 0; i < num_threads; ++i) {
        wait_for_worker(&comp->workers[i]);
    }
}