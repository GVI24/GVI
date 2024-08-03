#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

Node* insertNode(Node* head, const char* data) {
    if (head == NULL) {
        head = (Node*)malloc(sizeof(Node));
        if (head == NULL) {
            return NULL;  // Memory allocation failed.
        }
        head->data = strdup(data);
        head->next = NULL;
    } else {
        Node* current = head;
        // Memory leak: The loop never exits if data is already in the list.
        while (current->next != NULL && strcmp(current->data, data)) {
            current = current->next;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = strdup(data);
        newNode->next = NULL;
        current->next = newNode;
    }
    return head;
}

void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }
}

int main() {
    Node* list = NULL;
    list = insertNode(list, "data");

    // Potential non-terminating insertion if "data" is already present in the list.
    insertNode(list, "data");

    freeList(list);
    return 0;
}