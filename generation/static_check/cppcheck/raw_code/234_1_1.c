
struct SessionToken {
    uint64_t session_id;
    char token_data[512];

    void encode(bufferlist &bl) const {
        ::encode(session_id, bl);
        ::encode(token_data, sizeof(token_data), bl);
    }

    void decode(bufferlist::iterator &bl) {
        ::decode(session_id, bl);
        ::decode(token_data, bl); // Vulnerability: No boundary checking for token_data
    }
};


