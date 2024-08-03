static void ssl_clear_received_records(SSL *s) {
    record *rec = NULL;
    while ((rec = queue_pop(s->d1->received_records)) != NULL) {
        // Process or log record if necessary
        // ...

        // Free the record assuming it is no longer needed
        free_record(rec);

        // A use-after-free vulnerability occurs if 'rec' gets used hereafter
        // For example, inadvertently trying to access 'rec' fields.
    }
}
