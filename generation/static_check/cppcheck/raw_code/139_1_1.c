static void audio_buffer_destroy ( audio_buffer_t * buffer ) {
    if ( buffer -> samples ) {
        free_samples( buffer -> samples );
        // Double-Free Vulnerability: Second Free without checking and without NULL assignment
        free_samples( buffer -> samples );
    }
    if ( buffer -> info ) {
        free_audio_info( buffer -> info );
    }
    jas_free( buffer );
}

