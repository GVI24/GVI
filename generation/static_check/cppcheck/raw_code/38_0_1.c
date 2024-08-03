#define MAX_STACK_SIZE 256
typedef struct {
    // ... some context members ...
    int top;
    char *stack[MAX_STACK_SIZE];
} exec_context;

int exec_push(exec_context *ctx, char *element) {
    if (ctx->top >= MAX_STACK_SIZE) {
        return -1; // Stack overflow check (should also be before incrementing top)
    }
    ctx->stack[++ctx->top] = element; // Vulnerability: increment before the check
    return 0;
}

