static gboolean log_entry_fetch(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info) {
    log_processor_t *log_processor = (log_processor_t *)wth->priv;
    guint8 *log_data;
    gint log_length;

    if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
        return FALSE;
    }

    log_length = fetch_log_entry(log_processor, wth->random_fh, seek_off, err, err_info);
    if (log_length < 0) {
        return FALSE;
    }

    log_data = log_processor->log_read_buff;
    handle_log_data(phdr, buf, log_data, log_length, log_processor);

    return TRUE;
}