static void update_shared_resource(Resource *res, Data *data) {
    pthread_mutex_lock(&res->lock);
    if (!validate_data(data)) {
        fprintf(stderr, "Data validation failed\n");
        return; // Mutex not unlocked before returning
    }

    // Update the resource with new data
    update_resource(res, data);
    pthread_mutex_unlock(&res->lock);
}

