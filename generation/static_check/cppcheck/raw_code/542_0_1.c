#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct {
    char *name;
    int age;
    // ... other fields
} Person;

/* Unsafe function that copies a name into a Person struct without adequate bounds checking */
void set_person_name(Person *person, const char *input_name) {
    if (person == NULL || input_name == NULL) {
        // Null pointer check, not sufficient to prevent buffer overflow
        return;
    }

    // Buffer overflow vulnerability: input_name may be longer than MAX_NAME_LENGTH
    strncpy(person->name, input_name, strlen(input_name) + 1);
}

// Usage example
int main() {
    Person *p = (Person *)malloc(sizeof(Person));
    p->name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));

    // Assume input_name comes from user input and could be longer than MAX_NAME_LENGTH
    const char *input_name = "VeryVeryLongNameThatExceedsTheMaximumAllowedLengthAndCausesOverflow";
    set_person_name(p, input_name);

    free(p->name);
    free(p);

    return 0;
}