#include "retrospective.h"
#include "ringbuffer.h"
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

static log_level_t current_level = INFO;
static char logbuffer[LOG_MAX] = {};
static struct ringbuffer buf;

static void do_log(log_level_t level, const char *const fmt, va_list list)
{
    if (!buf.buffer)
    {
        buf = ringbuffer_alloc(4096);
    }

    size_t len = vsnprintf(logbuffer, sizeof(logbuffer), fmt, list);

    // Don't append null terminator
    ringbuffer_append(&buf, logbuffer, len);

    if (level >= current_level)
    {
        printf("%s", logbuffer);
    }
}

static void flush_buffer(void)
{
    printf("Dumping log buffer:\n");
    while (ringbuffer_remove(&buf, logbuffer, sizeof(logbuffer)) > 0)
    {
        printf("%s", logbuffer);
        memset(logbuffer, 0, sizeof(logbuffer));
    }
}

// Error logs trigger a flush of the logging buffer
void do_error(const char *const fmt, ...)
{
    // In an error situation, we want to see what was happening before
    flush_buffer();

    va_list list;
    va_start(list, fmt);

    do_log(ERROR, fmt, list);

    va_end(list);
}

void do_info(const char *const fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    do_log(INFO, fmt, list);

    va_end(list);
}

void do_debug(const char *const fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    do_log(DEBUG, fmt, list);

    va_end(list);
}
