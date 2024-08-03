void set_video_title(char *title, struct VideoContext *ctx) {
    // Vulnerability: No length check for the title, may cause buffer overflow if title is too long.
    strcpy(ctx->videoTitle, title); // Assuming videoTitle is a fixed size array in VideoContext.
}