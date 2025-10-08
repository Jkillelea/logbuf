#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

#define LOG_MAX 1024

typedef enum {
  DEBUG = 0,
  INFO = 1,
  ERROR = 2,
} log_level_t;

static log_level_t current_level = ERROR;
static char logbuffer[LOG_MAX] = {};
static size_t index = 0;

static void log(log_level_t level, const char *const fmt, ...) {
  va_list list;
  va_start(list, fmt);

  // TODO: we should use a ring buffer here. Keep the size static and just
  // overwrite. To do that we will probably need a separate buffer for each log
  // message and then we will append them to a ring buffer.
  index = (size_t)snprintf(&logbuffer[index], LOG_MAX, fmt, list);
  index = index % LOG_MAX;

  va_end(list);

  if (level >= current_level) {
    // print the current message.
  }
}

static void flush_buffer(void) {}

// Error logs trigger a flush of the logging buffer
void error(const char *const fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log(ERROR, fmt, list);
  va_end(list);

  // Print the entire buffer
  flush_buffer();
}

void info(const char *const fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log(INFO, fmt, list);
  va_end(list);
}

void debug(const char *const fmt, ...) {
  va_list list;
  va_start(list, fmt);
  log(DEBUG, fmt, list);
  va_end(list);
}
