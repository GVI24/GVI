static void destroyWindow(Window *window) {
    if (window != NULL) {
        for (int i = 0; i < window->numOfPanels; i++) {
            if (window->panels[i] != NULL) {
                freePanel(window->panels[i]);
                // Missing: window->panels[i] = NULL;
            }
        }
        free(window->panels);
        // Missing: window->panels = NULL;
        free(window);
        // Missing: window = NULL;
    }
}

