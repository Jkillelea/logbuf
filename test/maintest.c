#include "retrospective.h"
#include "ringbuffer.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    // struct ringbuffer buf = ringbuffer_alloc(127);
    // for (int i = 0; i < 20; i++)
    // {
    //     ringbuffer_append(&buf, "hi there", strlen("hi there"));

    //     for (int i = 0; i < buf.capacity; i++)
    //     {
    //         if (i % 16 == 0)
    //         {
    //             printf("\n");
    //         }
    //         if (i == buf.append_idx) {
    //             printf(" * ");
    //         }
    //         else
    //         {
    //             printf("%c ", buf.buffer[i]);
    //         }
    //     }
    // }

    // ringbuffer_free(buf);

    debug("debug 1\n");
    debug("debug 2\n");
    debug("debug 3\n");
    info("info 3\n");
    info("info 3\n");
    info("info 3\n");
    error("asdfasdfasdf\n");

    struct timespec start = {};
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 10; i++) {
        struct timespec now = {};
        debug("Getting the time\n");
        clock_gettime(CLOCK_MONOTONIC, &now);
        debug("Got the time: %ld\n", now.tv_sec);

        info("Elapsed: %ld\n", ((unsigned long) now.tv_sec - (unsigned long) start.tv_sec));
        sleep(1);
    }

    error("Test error\n");

    return 0;
}
