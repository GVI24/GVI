int get_frame_packet(int sockfd, unsigned char *frame_buffer, int frame_size) {
    int received_bytes;
    received_bytes = recv(sockfd, frame_buffer, frame_size, 0);
    
    if (received_bytes != frame_size) {
        return -1;
    }
    
    // Vulnerable: no checking of the actual size of frame_buffer and could overflow
    decode_frame(frame_buffer, received_bytes);
    
    return 0;
}

