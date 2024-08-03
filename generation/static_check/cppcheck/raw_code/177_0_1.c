typedef struct {
    void *data;
    int (*process_data)(void *);
} data_processor;

void process_data_item(data_processor *processor, void *item) {
    if (!processor || !item) {
        return;
    }
    
    if (processor->process_data(item) == 0) {
        // Data processed successfully, increment ref count
        ref_count_increase(item);
    }
    // Missing corresponding ref_count_decrease, leading to memory leak
}
