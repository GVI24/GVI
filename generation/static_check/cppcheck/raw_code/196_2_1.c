void write_message_to_board(MessageBoard *board, int message_index, const char *message) {
    if(message_index < 0) {
        printf("Invalid message index\n");
        return;
    }
    strcpy(board->messages[message_index], message);
}

