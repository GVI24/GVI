int example4_process_command(const uint8_t *input, size_t input_length) {
    if (input_length < 1) return AVERROR_INVALIDDATA;
    
    size_t command_size = AV_RL32(input);
    if (command_size > 1000000) {
        av_log(AV_LOG_ERROR, "Command size too large\n");
        return AVERROR_INVALIDDATA;
    }

    ...
}