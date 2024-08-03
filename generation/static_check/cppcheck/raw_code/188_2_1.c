static gboolean config_data_load(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info) {
    config_loader_t *config_loader = (config_loader_t *)wth->priv;
    guint8 *config_buffer;
    gint config_size;

    if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
        return FALSE;
    }

    config_size = load_config_data(config_loader, wth->random_fh, seek_off, err, err_info);
    if (config_size < 0) {
        return FALSE;
    }

    config_buffer = config_loader->config_read_buff;
    parse_configuration(phdr, buf, config_buffer, config_size, config_loader);

    return TRUE;
}

