#define MAX_NAME_LEN 64
void generate_user_tag(const char *first_name, const char *last_name) {
    char user_tag[MAX_NAME_LEN + 1];
    unsigned long k = 0;
    for (unsigned long i = 0; first_name[i] != '\0'; ++i) {
        user_tag[k++] = first_name[i];
    }
    user_tag[k++] = '.';
    for (unsigned long j = 0; last_name[j] != '\0'; ++j) {
        user_tag[k++] = last_name[j];
    }
    user_tag[k] = '\0';
    // Use the user tag for further processing which might lead to an overflow
    // ...
}