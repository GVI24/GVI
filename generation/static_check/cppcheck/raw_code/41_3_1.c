typedef struct {
    int16_t *left_channel;
    int16_t *right_channel;
    int length;
} StereoAudioStream;

static int mix_stereo_streams(StereoAudioStream *stream1, StereoAudioStream *stream2, StereoAudioStream *output_stream) {
    if (!stream1 || !stream2 || !output_stream) {
        return -1;
    }

    // Vulnerability: No check if stream1 and stream2 have the same length
    for (int i = 0; i < stream1->length; i++) {
        output_stream->left_channel[i] = (stream1->left_channel[i] + stream2->left_channel[i]) / 2; // Potential out-of-bounds read/write
        output_stream->right_channel[i] = (stream1->right_channel[i] + stream2->right_channel[i]) / 2; // Potential out-of-bounds read/write
    }

    // Output length should be set properly
    output_stream->length = stream1->length;

    return 0;
}