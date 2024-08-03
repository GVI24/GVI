static gboolean image_data_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info) {
    image_reader_t *img_reader = (image_reader_t *)wth->priv;
    guint8 *image_buffer;
    gint image_size;

    if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
        return FALSE;
    }

    image_size = read_image_data(img_reader, wth->random_fh, seek_off, TRUE, err, err_info);
    if (image_size < 0) {
        return FALSE;
    }

    image_buffer = img_reader->image_read_buff;
    process_image_data(phdr, buf, image_buffer, image_size, img_reader);

    return TRUE;
}

