#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

/**
 * 参考Linux kfifo源码
 */

typedef struct ring_buffer {
    char *buf;    /* the buffer holding the data */
    uint32_t size;    /* the size of the allocated buffer */
    uint32_t in;    /* data is added at offset (in % size) */
    uint32_t out;    /* data is extracted from off. (out % size) */
    uint32_t mask;
}ring_buffer_t;

typedef int8_t rb_err_t;

#define RB_ERR_OK  0
#define RB_ERR_ERR -1

void rb_init(ring_buffer_t *rb, char *buf, uint32_t size);
uint32_t rb_in(ring_buffer_t *rb, char *buf, uint32_t len);
uint32_t rb_out(ring_buffer_t *rb, char *buf, uint32_t len);

#endif
