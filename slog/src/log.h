#ifndef LOG_H
#define LOG_H

#include <syslog.h>

int slog_interactive(void);
int slog(int level, char* message);

#endif /* !LOG_H */
