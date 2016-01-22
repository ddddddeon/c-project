#include "hklog.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void hklog(int level, char* format, ...) {
  if (strlen(format) > HK_MSGLENGTH_LIMIT) {
    printf("%s[%slog message too long!%s]%s %s\n", HK_WHITE_BOLD, HK_RED_BOLD, 
	   HK_WHITE_BOLD, HK_UNCOLOR, format);
    return;
  }

  va_list args;
  int msg_size = ((int)strlen(format)) + HK_LOGPREFIX_LENGTH;
  char message[msg_size];
  sprintf(message, "%s[%sLOGGER%s]%s %s", HK_WHITE_BOLD, HK_RED_BOLD,
	  HK_WHITE_BOLD, HK_UNCOLOR, format);

#ifdef HKLOG_DEBUG
  printf("constructed log message: %s\n", message);
#endif

  va_start(args, message);
  vprintf(message, args);
  va_end(args);
}
