static void send_data_to_channel(NetworkController *net, int channel_id, char *data) {
    Channel *channel;
    
    // Buffer overflow vulnerability: No upper limit check for channel_id.
    if (channel_id < 0 || channel_id > net->max_channels) {
        printf("Invalid channel ID\n");
        return;
    }
    
    channel = net->channels[channel_id];
    if (channel->status != CHANNEL_ACTIVE) {
        printf("Channel is not active\n");
        return;
    }
    
    // Send data to active channel...
}

