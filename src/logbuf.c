#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define LOG_MAX 1024

typedef enum
{
    DEBUG = 0,
    INFO = 1,
    ERROR = 2,
} log_level_t;

static log_level_t current_level = ERROR;
static char logbuffer[LOG_MAX] = {};
static size_t idx = 0;

static void log(log_level_t level, const char *const fmt, ...)
{
    size_t newindex = 0;
    va_list list;
    va_start(list, fmt);

    // TODO: we should use a ring buffer here. Keep the size static and just
    // overwrite. To do that we will probably need a separate buffer for each log
    // message and then we will append them to a ring buffer.
    newindex = (size_t)snprintf(&logbuffer[idx], LOG_MAX, fmt, list);

    va_end(list);

    if (level >= current_level)
    {
        printf("%s", &logbuffer[idx]);
    }

    idx = newindex % LOG_MAX;
}

static void flush_buffer(void)
{
    printf("%s", logbuffer);
    memset(logbuffer, 0, sizeof(logbuffer));
}

// Error logs trigger a flush of the logging buffer
void error(const char *const fmt, ...)
{
    // In an error situation, we want to see what was happening before
    flush_buffer();

    va_list list;
    va_start(list, fmt);

    log(ERROR, fmt, list);

    va_end(list);
}

void info(const char *const fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    log(INFO, fmt, list);

    va_end(list);
}

void debug(const char *const fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    log(DEBUG, fmt, list);

    va_end(list);
}
