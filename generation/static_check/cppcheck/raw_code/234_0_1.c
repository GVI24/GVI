
struct UserCredentials {
    uint64_t user_id;
    char username[64];
    char password[128];

    void encode(bufferlist &bl) const {
        ::encode(user_id, bl);
        ::encode(username, sizeof(username), bl);
        ::encode(password, sizeof(password), bl);
    }

    void decode(bufferlist::iterator &bl) {
        ::decode(user_id, bl);
        ::decode(username, bl); // Vulnerability: No size check before writing to the buffer
        ::decode(password, bl); // Vulnerability: No size check before writing to the buffer
    }
};


