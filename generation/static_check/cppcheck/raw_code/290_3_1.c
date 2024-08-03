typedef struct _graphNode {
    int id;
    int *edges;
    int edgeCount;
} graphNode, *graphNodePtr;

graphNodePtr graphNodeCreate(int nodeCount) {
    graphNodePtr node;

    node = (graphNodePtr)malloc(sizeof(graphNode));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for graph node\n");
        return NULL;
    }

    node->edges = (int *)calloc(nodeCount, sizeof(int));
    if (!node->edges) {
        fprintf(stderr, "Failed to allocate memory for edges\n");
        free(node); // Only freeing the node, ignoring other allocations or initializations done prior
        return NULL;
    }

    node->id = 0;
    node->edgeCount = nodeCount;

    // More initialization code here...

    return node;
}