#include "minunit.h"
#include <lcthw/ringbuffer.h>
#include <assert.h>

static RingBuffer *ringbuffer = NULL;

char *test_create()
{
    ringbuffer = RingBuffer_create(7);
    mu_assert(ringbuffer, "Failed to create a ringbuffer.");

    return NULL;
}

char *test_destroy()
{
    mu_assert(ringbuffer != NULL, "Failed to destroy the ringbuffer.");
    RingBuffer_destroy(ringbuffer);

    return NULL;
}

char *test_read_write()
{
    char *foo = "abcd";
	RingBuffer_write(ringbuffer, foo, 4);

	char *tmp = calloc(sizeof(char), 2);
	RingBuffer_read(ringbuffer, tmp, 2);
    mu_assert(tmp[0] == 'a' && tmp[1] == 'b', "Read wrong value.");



	char *foo2 = "g";
	char *tmp2 = calloc(sizeof(char), 3);
	RingBuffer_write(ringbuffer, foo2, 1);
	RingBuffer_read(ringbuffer, tmp2, 3);

	mu_assert(tmp2[0] == 'c' && tmp2[1] == 'd' && tmp2[2] == 'g', "Read wrong value.");

    return NULL;
}

char *all_tests() {
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_read_write);
    mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);