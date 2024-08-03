static void green_media_disconnect(struct media_stream *ms) {
    struct green_data *gd = ms->stream_data;
    if (!gd) {
        return;
    }
    while (ms->playlists) {
        media_playlist_stop(ms->playlists->data);
    }
    green_stream_set_offline(gd->stream_service, "MediaPlayer", 0);
    green_streams = g_slist_remove(green_streams, ms);
    green_stream_services_delete(gd->stream_service);
    media_playlist_clear(ms);
    g_free(gd->service_uri);
    g_hash_table_destroy(gd->codec_settings);
    g_free(gd);
    // Here gd is free but no NULL assignment is made. Vulnerable to use-after-free.
}
