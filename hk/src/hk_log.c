#include "hk_log.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void hk_log(const char *caller, int level, char *format, ...) {
  va_list args;
  char *color;
  char *color_bold;
  char *level_string;
  char prefix[128];

  switch (level) {
    case HK_DEBUG:
      color = HK_MAGENTA;
      color_bold = HK_MAGENTA_BOLD;
      level_string = "DEBUG";
      break;
    case HK_INFO:
      color = HK_CYAN;
      color_bold = HK_CYAN_BOLD;
      level_string = "INFO";
      break;
    case HK_WARN:
      color = HK_YELLOW;
      color_bold = HK_YELLOW_BOLD;
      level_string = "WARN";
      break;
    case HK_ERR:
      color = HK_RED;
      color_bold = HK_RED_BOLD;
      level_string = "ERROR";
      break;
    case HK_FATAL:
      color = HK_RED;
      color_bold = HK_RED_BOLD;
      level_string = "FATAL";
      break;
    default:
      color = HK_MAGENTA;
      color_bold = HK_MAGENTA_BOLD;
      level_string = "LOGGER";
  }

  sprintf(prefix, "%s[%s%s%s][%s%s%s]:%s ",
	  HK_WHITE_BOLD, color_bold, level_string, HK_WHITE_BOLD,
	  color, caller, HK_WHITE_BOLD, HK_UNCOLOR);

  printf("%s", prefix);
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}
