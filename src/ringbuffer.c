// ringbuffer implementation

#include <stdio.h>
#include <string.h>

#define RINGBUFFER_SIZE 4096

#define MIN(a, b) (a > b ? b : a)

struct ringbuffer
{
    size_t idx;
    char buffer[RINGBUFFER_SIZE];
};

void ringbuffer_append(struct ringbuffer *buffer, const char *const str, const size_t len)
{
    if (!buffer)
    {
        return;
    }

    if (!str)
    {
        return;
    }

    // Copy the first part in
    size_t firstsize = MIN(len, sizeof(buffer->buffer) - buffer->idx);
    memcpy(&buffer->buffer[buffer->idx], str, firstsize);
    buffer->idx += firstsize;
    buffer->idx %= sizeof(buffer->buffer);
}
