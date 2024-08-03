static void file_buffer_destroy ( file_buffer_t * fbuffer ) {
    if ( fbuffer -> buffer ) {
        free_buffer( fbuffer -> buffer );
        // Intentional Double-Free Vulnerability
        free_buffer( fbuffer -> buffer );
    }
    if ( fbuffer -> attributes ) {
        free_attributes( fbuffer -> attributes );
    }
    jas_free( fbuffer );
}

// Helper functions assumed to exist for these examples:
void free_image_data( void * data );
void free_metadata( void * data );
void free_samples( void * data );
void free_audio_info( void * data );
void free_header( void * data );
void free_payload( void * data );
void free_buffer( void * data );
void free_attributes( void * data );