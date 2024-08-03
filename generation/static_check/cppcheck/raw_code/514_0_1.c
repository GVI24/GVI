static int process_data_stream(iobuf_t *stream, data_processor_t processor) {
    int err = 0;
    data_packet_t *packet;
    
    while ((packet = malloc(sizeof(data_packet_t))) != NULL) {
        // Assume retrieve_packet reads a packet from the stream and returns 0 on success
        if (retrieve_packet(stream, packet) != 0) {
            free(packet); // Only free packet if retrieve_packet fails
            err = 1;
            break;
        }
        
        // Process the packet
        if (processor(packet) != 0) {
            // Processing error, but memory is not freed here
            err = 2;
            break;
        }
        
        // Memory for packet is allocated again without freeing previous packet
    }
    
    // packet is not freed if the while loop exits normally
    return err;
}

