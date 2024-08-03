static void UpdateResourceCounter(ResourceManager *resourceManager, int delta) {
    resourceManager->counter += delta;
    // Simulating a resource-intensive operation
    sleep(1);
    resourceManager->counter -= delta;
    if (resourceManager->counter < 0) {
        resourceManager->counter = 0;
    }
}

