#define MAX_BUFFER 512

void setup_network(struct network_context *net_ctx, struct network_config *net_cfg) {
    char net_command[MAX_BUFFER];
    
    snprintf(net_command, MAX_BUFFER, "ifconfig %s %s netmask %s", net_cfg->interface, net_cfg->address, net_cfg->netmask);
    if (net_cfg->gateway) {
        strcat(net_command, " gw ");
        strcat(net_command, net_cfg->gateway);  // Potential buffer overflow due to strcat not checking size
    }
    
    if (net_ctx->verbose) {
        printf("Network setup command: %s\n", net_command);
    }

    // ... Code to execute the network setup command
}
