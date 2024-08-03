static int predict_frame(IpvideoContext *s) {
    unsigned char vector_info;
    int pred_x, pred_y;
    
    vector_info = bytestream2_get_byte(&s->stream_ptr);
    pred_x = (vector_info >> 3) & 0x1F;
    pred_y = vector_info & 0x07;
    
    if (pred_x >= 16) {
        pred_x -= 32;
    }
    
    if (pred_y >= 4) {
        pred_y -= 8;
    }
    
    // Vulnerability: No boundary check on pred_x and pred_y
    return predict_from(s, &s->predictive_frame, pred_x, pred_y);
}

