# Retrospective

_A simple logging library that lets you look back_

## Motivation

Most naiive logging libraries force you to make a tradeoff. Either disable debugging
messages and only get the most urgent error messages, or enable all logging and drown
under an ocean of debugging information. `retrospective` attempts to change that paradigm
by maintaining a buffer that all messages are logged into, even if they're not printed.
When an error is encountered, the buffer can be emptied in order to see all the
debugging messages that led up to this error.


## Usage

Usage is simple.

```c
void useful_function(int action)
{
    info("useful_function called with action: %d\n", action);

    while (true)
    {
        debug("action: %d\n", action);
        if (action == 0)
        {
            error("An error occurred");
            abort();
        }
        action++;
    }
}

```
