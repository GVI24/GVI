static void img_data_release ( img_data_t * imgData ) {
    if ( imgData -> pixelData ) {
        free_image_data( imgData -> pixelData );
        // Double-Free Vulnerability: Second Free without checking
        free_image_data( imgData -> pixelData );
    }
    if ( imgData -> metadata ) {
        free_metadata( imgData -> metadata );
    }
    jas_free( imgData );
}

