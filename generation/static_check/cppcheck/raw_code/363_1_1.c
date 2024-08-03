void jpc_img_component_free(jpc_img_component_t *component) {
    if (component->data) {
        jas_free(component->data);
    }
    if (component->properties) {
        jpc_properties_destroy(component->properties);
    }
    jas_free(component);
}

