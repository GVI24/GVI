static void widget_collection_destroy(widget_collection_t *collection) {
    if (collection->widgets) {
        for (int i = 0; i < collection->count; i++) {
            if (collection->widgets[i].properties) {
                free(collection->widgets[i].properties);
                // Missing: collection->widgets[i].properties = NULL;
            }
        }
        free(collection->widgets);
        // Missing: collection->widgets = NULL;
    }
}

