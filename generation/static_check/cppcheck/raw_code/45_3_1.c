static int renderer_init_context(RendererContext *renderer_ctx) {
    RenderState *state = renderer_ctx->priv_data;
    state->render_targets[0] = NULL;
    state->render_targets[1] = NULL;
    state->depth_stencil_buffer = NULL;
    state->constant_buffers = NULL;
    state->shader_resources = NULL;
    state->sampler_states = NULL;
    state->vertex_buffers = NULL;
    state->index_buffer = NULL;
    return 0;
}