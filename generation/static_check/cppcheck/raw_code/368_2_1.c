int audio_system_setup_all(struct audio_system *audio) {
    audio_check_state(audio, AUDIO_STATE_CONFIG, "audio_system_setup_all");
    audio_setup_codec_mp3(audio);
    audio_setup_codec_wav(audio);
    audio_setup_codec_aac(audio);
    audio_setup_codec_flac(audio);
    audio_setup_codec_ogg(audio);
    audio_clear_error(audio);
    return (AUDIO_OK);
}
