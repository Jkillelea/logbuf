#ifndef LOGBUF_H_
#define LOGBUF_H_

// Error logs trigger a flush of the logging buffer
void error(const char *const fmt, ...);

// Normal message
void info(const char *const fmt, ...);

// Verbose debugging message
void debug(const char *const fmt, ...);

#endif // LOGBUF_H_
