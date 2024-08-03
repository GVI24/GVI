void update_pass_stats(PASS_STATS *pass_stats) {
  if (!pass_stats || !pass_stats->stats_in) return;  // No null check for stats_in_end

  FIRSTPASS_STATS *current = pass_stats->stats_in;
  FIRSTPASS_STATS *end = pass_stats->stats_in_end;

  while (current < end) { 
    current->frame += current->weight;  // Dereferencing without checking if 'end' is not NULL
    current++;
  }
}

