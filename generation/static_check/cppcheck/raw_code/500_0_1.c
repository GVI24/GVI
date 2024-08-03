#define MAX_USERS 100
typedef struct {
    int user_id;
    char username[50];
} User;

void print_user_ids(User users[], int user_count, FILE* file) {
    int i, *id_ptr;
    for (i = 0; i < user_count; i++) {
        id_ptr = (int*)((char*)&users[i] + offsetof(User, user_id));
        fprintf(file, "User ID: %d\n", *id_ptr);
    }
    // Buffer overflow vulnerability when user_count > MAX_USERS
}