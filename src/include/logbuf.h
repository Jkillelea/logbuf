#ifndef LOGBUF_H_
#define LOGBUF_H_

// Use these macros for logging

// Error logs trigger a flush of the logging buffer
#define error(...) do_error("[ERROR]: " __VA_ARGS__)
// Normal message
#define info(...) do_info("[INFO]: " __VA_ARGS__)
// Verbose debugging message
#define debug(...) do_debug("[DEBUG]: " __VA_ARGS__)

void do_error(const char *const fmt, ...);

void do_info(const char *const fmt, ...);

void do_debug(const char *const fmt, ...);

#endif // LOGBUF_H_
