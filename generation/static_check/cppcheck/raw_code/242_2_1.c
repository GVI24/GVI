typedef struct {
    int id;
    char name[50];
} Person;

Person *addPerson(Person *people, int *count, int *maxCount, Person newPerson) {
    if (*count >= *maxCount) {
        *maxCount += 5; // Increment maxCount by 5
        Person *newPeople = (Person *)realloc(people, (*maxCount) * sizeof(Person));
        if (!newPeople) {
            return NULL;
        }
        people = newPeople;
    }
    people[*count] = newPerson;
    (*count)++;
    return people;
}

