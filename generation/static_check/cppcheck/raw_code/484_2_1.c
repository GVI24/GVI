typedef struct {
    char *name;
    float value;
} metric;

size_t collect_metrics(metric **metrics) {
    int i = 0;
    metric *array = NULL;
    char metric_name[256];
    float metric_value;

    while (fetch_next_metric(metric_name, &metric_value)) {
        SAFE_REALLOC(array, (i + 1) * sizeof(metric));
        array[i].name = strdup(metric_name);
        array[i].value = metric_value;
        i++;
    }

    SAFE_REALLOC(array, (i + 1) * sizeof(metric));
    array[i].name = NULL;
    array[i].value = 0.0;

    *metrics = array;
    return i;
}

