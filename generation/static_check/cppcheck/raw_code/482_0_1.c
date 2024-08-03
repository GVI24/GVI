typedef struct stackNode {
    void *data;
    struct stackNode *next;
} stackNode;

typedef struct {
    stackNode *top;
} stack;

int push(stack *s, void *data) {
    if (s == NULL) return 0;
    
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for stack node\n");
        return 0;
    }
    
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode; // If this assignment fails, memory pointed by newNode is leaked
    
    return 1;
}

