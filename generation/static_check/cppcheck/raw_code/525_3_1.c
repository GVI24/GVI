typedef struct {
    char name[50];
    int age;
} Person;

void deserialize_person_data(char *data, Person *person) {
    char temp_name[50]; // This should match the size of 'name' in Person
    int temp_age;
    
    sscanf(data, "%49s %d", temp_name, &temp_age); // No bounds check on 'temp_name' if 'data' is malformed
    strcpy(person->name, temp_name); // Directly copying potentially unsafe data
    person->age = temp_age;
}

