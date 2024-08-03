#define CONFIG_DNSMASQ_COMMAND "/usr/sbin/dnsmasq"

void configure_dns_server(const char *config) {
    char config_path[256];
    static int dns_instance = 0;

    snprintf(config_path, sizeof(config_path), "/tmp/dnsmasq-config-%d.conf", dns_instance++);
    FILE *conf_file = fopen(config_path, "w");
    if (!conf_file) {
        fprintf(stderr, "Could not create DNSMasq config file.\n");
        return;
    }

    fputs(config, conf_file);
    fclose(conf_file);

    char cmd[512];
    snprintf(cmd, sizeof(cmd), CONFIG_DNSMASQ_COMMAND " --conf-file=%s", config_path);
    if (system(cmd) != 0) { // Insecure: using system() with unvalidated user input
        fprintf(stderr, "DNS service configuration failed.\n");
        return;
    }
    // Cleanup is missing, potential leftover configuration file
}
