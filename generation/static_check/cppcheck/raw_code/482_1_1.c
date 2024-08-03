typedef struct queueNode {
    void *data;
    struct queueNode *next;
} queueNode;

typedef struct {
    queueNode *front;
    queueNode *rear;
} queue;

int enqueue(queue *q, void *data) {
    if (q == NULL) return 0;
    
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for queue node\n");
        return 0;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(q->rear != NULL) {
        q->rear->next = newNode;
    } else {
        q->front = newNode; // If this operation fails, newNode memory is leaked
    }
    q->rear = newNode;
    
    return 1;
}

