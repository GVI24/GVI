static int parse_message_type(tvbuff_t *tvb, int offset, guint8 *msg_type) {
    guint8 tmp_msg_type = tvb_get_guint8(tvb, offset);
    switch (tmp_msg_type) {
    case MSG_TYPE_REQUEST:
        *msg_type = MSG_TYPE_REQUEST;
        break;
    case MSG_TYPE_RESPONSE:
        *msg_type = MSG_TYPE_RESPONSE;
        break;
    case MSG_TYPE_NOTIFICATION:
        *msg_type = MSG_TYPE_NOTIFICATION;
        break;
    default:
        DISSECTOR_ASSERT(FALSE);  // Vulnerability: Use of assertion
        break;
    }
    return offset + 1;
}

