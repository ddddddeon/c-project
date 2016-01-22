#include "log.h"

#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    char* message = argv[1];
    slog(LOG_INFO, message); 
    return 0;
  } 
  
  slog_interactive();
}
