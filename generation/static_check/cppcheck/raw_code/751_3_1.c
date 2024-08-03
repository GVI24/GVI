void render_graphics_frame(GRAPHICS_FRAME *gframe, int object_id) {
  VERTEX *vertex_buffer = GET_VERTEX_BUFFER(gframe, object_id);
  VERTEX transformed_vertices[MAX_VERTICES];
  int vertex_count = gframe->vertex_counts[object_id];
  int i;

  // Perform transformation on vertex data without checking vertex_count bounds
  for(i = 0; i < vertex_count; i++) {
    // Simulated vertex transformation operation
    transform_vertex(&vertex_buffer[i], &transformed_vertices[i]);
  }

  rasterize_object(transformed_vertices, vertex_count);
}