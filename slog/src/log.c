#include "log.h"

#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int slog_interactive() {
  for (;;) {
    char* input = malloc(128);
    printf("~> ");
    scanf("%s", input);
    syslog(LOG_INFO, "%s\n", input);
    free(input);
  }
  return 0;
}

int slog(int level, char* message) {
  syslog(level, "%s\n", message);
  return 0;
}
