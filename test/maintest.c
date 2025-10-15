#include "logbuf.h"
#include "ringbuffer.h"
#include <stdio.h>
#include <string.h>

int main()
{
    struct ringbuffer buf = ringbuffer_alloc(127);
    for (int i = 0; i < 20; i++)
    {
        ringbuffer_append(&buf, "hi there", strlen("hi there"));

        for (int i = 0; i < buf.capacity; i++)
        {
            if (i % 16 == 0)
            {
                printf("\n");
            }
            if (i == buf.append_idx) {
                printf(" * ");
            }
            else
            {
                printf("%c ", buf.buffer[i]);
            }
        }
    }


    debug("debug 1\n");
    debug("debug 2\n");
    debug("debug 3\n");
    error("asdfasdfasdf\n");

    ringbuffer_free(buf);

    return 0;
}
