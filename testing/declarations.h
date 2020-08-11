#ifndef _declarations
#define _declarations

#include <stdint.h>
#include <unistd.h>

typedef int64_t (*int64_feed_t)();

int64_t next_even_number();

int64_t calc_factorial(int64_feed_t feed);

#endif
