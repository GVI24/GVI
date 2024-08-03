#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 256

typedef struct HashNode {
    char* key;
    void* value;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    HashNode* buckets[HASH_TABLE_SIZE];
} HashTable;

unsigned long hashFunction(const char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_TABLE_SIZE;
}

int hashTableInsert(HashTable* table, const char* key, void* value) {
    if (table == NULL || key == NULL) {
        return -1;
    }

    unsigned long index = hashFunction(key);
    HashNode* node = table->buckets[index];

    // Potential infinite loop if hash collision occurs many times
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            // Key already exists.
            return -1;
        }
        node = node->next;
    }

    // Memory leak: No check for successful allocation.
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
    
    return 0;
}

void hashTableFree(HashTable* table) {
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        HashNode* node = table->buckets[i];
        while (node != NULL) {
            HashNode* tmp = node;
            node = node->next;
            free(tmp->key);
            free(tmp);
        }
    }
}

int main() {
    HashTable table = {{0}};
    hashTableInsert(&table, "key", "value");

    // If "key" causes a hash collision, this can lead to performance degradation.
    hashTableInsert(&table, "key", "newvalue");

    hashTableFree(&table);
    return 0;
}