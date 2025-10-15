// ringbuffer implementation

#include "ringbuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (a > b ? b : a)

struct ringbuffer ringbuffer_alloc(size_t capacity)
{
    struct ringbuffer buf = {
        .append_idx = 0,
        .remove_idx = 0,
        .capacity = capacity,
        .buffer = (char *)calloc(capacity, sizeof(char)),
    };

    return buf;
}

void ringbuffer_free(struct ringbuffer buf)
{
    if (buf.buffer)
    {
        free(buf.buffer);
        buf.capacity = 0;
    }
}

void ringbuffer_append(struct ringbuffer *buffer, const char *const str, const size_t len)
{
    if (!buffer)
    {
        return;
    }

    if (!buffer->buffer)
    {
        return;
    }

    if (!str)
    {
        return;
    }

    // Most naiive implementation
    for (size_t i = 0; i < len; i++)
    {
        buffer->buffer[buffer->append_idx] = str[i];
        buffer->append_idx = (buffer->append_idx + 1) % buffer->capacity;
    }
}

ssize_t ringbuffer_remove(struct ringbuffer *buffer, char *const str, const size_t len)
{
    ssize_t nread = 0;
    if (!buffer)
    {
        return -1;
    }

    if (!buffer->buffer)
    {
        return -1;
    }

    if (!str)
    {
        return -1;
    }

    while (buffer->remove_idx != buffer->append_idx)
    {
        str[nread] = buffer->buffer[buffer->remove_idx];
        buffer->remove_idx = (buffer->remove_idx + 1) % buffer->capacity;
        nread++;
    }

    return nread;
}
