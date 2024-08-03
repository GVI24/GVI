typedef struct {
  void *render_data;
  int width;
  int height;
  int channels;
} RenderContext;

// Vulnerable function to create a new rendering context based on provided dimensions
RenderContext *render_context_create(int width, int height, int channels) {
  RenderContext *context = (RenderContext *)calloc(1, sizeof(RenderContext));
  // Missing allocation failure check
  int buffer_size = width * height * channels;
  context->render_data = malloc(buffer_size); // Potential integer overflow and NULL dereference
  context->width = width;
  context->height = height;
  context->channels = channels;
  return context;
}