static void launch_video_file(GtkWidget *parent, const char *video_path) {
    char *codec;
    GtkWidget *dialog;

    codec = get_required_codec(video_path);

    if (codec && !is_codec_installed(codec)) {
        dialog = gtk_message_dialog_new(parent,
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_INFO,
                                        GTK_BUTTONS_YES_NO,
                                        "The codec '%s' is required to play this file. Install now?",
                                        codec);
        
        g_signal_connect(dialog, "response", 
                         G_CALLBACK(on_codec_install_response), strdup(codec));
        
        gtk_widget_show(dialog);
        free(codec);
        return;
    }

    play_video_file(video_path);
    // Forgot to free() the codec string if the codec is already installed.
}

