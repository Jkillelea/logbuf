#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <stdio.h>

struct ringbuffer
{
    size_t append_idx;
    size_t remove_idx;
    size_t capacity;
    char *buffer;
};

// Dynamically allocate a buffer. struct ringbuffer is created on the stack though!
struct ringbuffer ringbuffer_alloc(size_t capacity);

// Free the buffer. DOES NOT FREE struct ringbuffer *buf, that should be on the stack!
void ringbuffer_free(struct ringbuffer buf);

// Append bytes, overwriting.
void ringbuffer_append(struct ringbuffer *const buffer, const char *const str, const size_t len);

// Remove bytes up until the read index reaches the write index.
ssize_t ringbuffer_remove(struct ringbuffer *const buffer, char *const str, const size_t len);

#endif // RINGBUFFER_H_
