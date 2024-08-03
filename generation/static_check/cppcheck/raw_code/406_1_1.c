static void update_service_configs(void) {
    int svc_number;
    for (svc_number = 0; svc_number < services_count; svc_number++) {
        char config_path[512];
        ServiceConfig *svc_config = &service_configs[svc_number];
        printf("Updating configuration for service: %s\n", svc_config->service_name);

        // Vulnerability: Including unsanitized service configuration in the command
        sprintf(config_path, "/usr/bin/service_manager --update \"%s\" \"%s\"",
                svc_config->service_name, svc_config->config_data);

        // Running the possibly dangerous config update command
        system(config_path);
    }
}

