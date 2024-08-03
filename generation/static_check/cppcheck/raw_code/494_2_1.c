typedef struct {
    char name[50];
    char email[100];
    int age;
} UserInfo;

int update_user_info(UserInfo *dst, const UserInfo *src) {
    // Potential buffer overflow vulnerability
    memcpy(dst, src, sizeof(UserInfo) + 10); // Incorrect size

    // Copy additional data
    dst->age = src->age + 1;

    return 0;
}