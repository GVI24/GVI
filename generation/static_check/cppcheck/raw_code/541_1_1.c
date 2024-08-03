void configure_audio_profile(AUDIO_CODEC *codec, int profile) {
    assert(profile >= 0 && profile <= MAX_AUDIO_PROFILE);

    codec->profile = profile;
    
    // Assuming that certain profiles require a specific sample rate
    if (codec->profile == HIGH_QUALITY_PROFILE) {
        assert(codec->sample_rate == HIGH_QUALITY_SAMPLE_RATE);
    } else {
        codec->sample_rate = STANDARD_SAMPLE_RATE; // Sets to a default if not high quality
    }
    
    // ... Additional configuration code
}