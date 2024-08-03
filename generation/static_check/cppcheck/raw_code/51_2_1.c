static void create_histogram(DATA_SET *data_set, int num_bins) {
    int i;

    data_set->histogram = (int *)calloc(num_bins, sizeof(int));

    // Vulnerability pattern: no check for NULL after calloc
    for (i = 0; i < data_set->num_data_points; i++) {
        int bin_index = data_set->data_points[i] % num_bins;
        data_set->histogram[bin_index]++;
    }
}

