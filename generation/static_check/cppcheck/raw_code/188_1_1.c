static gboolean audio_data_decode(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info) {
    audio_decoder_t *audio_decoder = (audio_decoder_t *)wth->priv;
    guint8 *audio_data;
    gint data_len;

    if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
        return FALSE;
    }

    data_len = decode_audio_frame(audio_decoder, wth->random_fh, seek_off, err, err_info);
    if (data_len < 0) {
        return FALSE;
    }

    audio_data = audio_decoder->audio_decode_buff;
    process_decoded_audio(phdr, buf, audio_data, data_len, audio_decoder);

    return TRUE;
}

