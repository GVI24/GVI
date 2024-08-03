typedef struct {
    int id;
    char *name;
    size_t name_length;
} User;

User *parse_user_data(const uint8_t *data, size_t data_size) {
    User *user;
    size_t name_length;

    if (data_size < 5) return NULL; // Not enough data for an ID and name length
    
    user = malloc(sizeof(User));
    if (user == NULL) return NULL;

    user->id = *((int *)data);
    name_length = data[4];
    
    // No check to guarantee that name_length is within the bounds of data_size
    user->name = malloc(name_length + 1); // plus null terminator
    if (user->name == NULL) {
        free(user);
        return NULL;
    }

    // Potential buffer over-read if name_length is incorrect
    memcpy(user->name, data + 5, name_length);
    user->name[name_length] = '\0'; // Null terminate the string
    
    user->name_length = name_length;
    return user;
}