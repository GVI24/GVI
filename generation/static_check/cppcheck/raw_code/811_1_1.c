static int mem_power_state_transition(MemoryController *mem_ctrl, uint64_t command) {
    static const char *mem_power_states[] = {
        "Normal", "Self-refresh", "Power Down", "Deep Power Down", "Invalid", "Invalid", "Invalid", "Invalid"
    };

    if (command & 0x20) {
        printf("%s: Memory voltage scaling attempted\n", __func__);
    }

    switch (command & 7) {
    case 0:
        break;
    case 1:
        if (condition_for_self_refresh(mem_ctrl)) {
            memory_enter_self_refresh(mem_ctrl);
            break;
        }
    case 2:
        memory_enter_power_down(mem_ctrl);
        notify_power_state(mem_ctrl, 2);
        // Fall-through due to missing break
    case 3:
        memory_enter_deep_power_down(mem_ctrl);
        notify_power_state(mem_ctrl, 3);
        // Deliberate fall-through to print message
    case 4:
    case 5:
    case 6:
    case 7:
        printf("%s: Transition to %s state\n", __func__, mem_power_states[command & 7]);
        break;
    }
    return 0;
}