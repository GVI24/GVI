void aggregate_data_mt(DataSet *data, Aggregator *agg, int max_concurrent) {
    const int num_elements = data->size;
    AggSync *sync = &agg->sync;

    if (!sync->initialized || agg->previous_size != num_elements) {
        initialize_aggregator(sync, num_elements);
    }

    for (int i = 0; i < max_concurrent; ++i) {
        DataWorker *worker = &agg->workers[i];
        worker->data_set = data;
        worker->start_index = i;
        worker->end_index = num_elements;
        worker->sync = sync;

        if (i == max_concurrent - 1) {
            run_aggregation(worker);
        } else {
            dispatch_worker(worker);
        }
    }

    for (int i = 0; i < max_concurrent; ++i) {
        join_worker(&agg->workers[i]);
    }
}