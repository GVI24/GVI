#define MAX_SUBTITLE_SIZE 1024

typedef struct {
    char subtitle_text[MAX_SUBTITLE_SIZE];
} SubtitleDecoderContext;

int parse_subtitle_packet(SubtitleDecoderContext *ctx, const char *packet_data, size_t packet_length) {
    // Vulnerable: No check on the length of the incoming subtitle packet
    if (packet_length < 3) { // Check for minimum required header size
        fprintf(stderr, "Packet too short for subtitles\n");
        return -1;
    }

    uint16_t text_length = packet_data[1] << 8 | packet_data[2]; // Extracting text length from packet header

    // Vulnerability: no bounds check on text_length before copying
    if (text_length >= MAX_SUBTITLE_SIZE) {
        fprintf(stderr, "Subtitle packet too large\n");
        return -1;
    }

    strncpy(ctx->subtitle_text, packet_data + 3, text_length); // Unsafe copy

    // Subtitle text post-processing...

    return 0;
}