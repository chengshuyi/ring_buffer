#include "ring_buffer.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

void rb_init(ring_buffer_t *rb, char *buf, uint32_t size)
{
    rb->buf = buf;
    rb->in = 0;
    rb->out = 0;
    if ((size & (size - 1)) != 0)
    {
        // return;
    }
    rb->size = size;
    rb->mask = size - 1;
}

uint32_t rb_in(ring_buffer_t *rb, char *buf, uint32_t len)
{
    uint32_t l;
    // len表示剩余容量
    len = min(len, rb->size - rb->in + rb->out);
    l = min(len, rb->size - (rb->in & rb->mask));
    memcpy(rb->buf + (rb->in & rb->mask), buf, l);
    memcpy(rb->buf, buf + l, len - l);
    // 不需要MASK
    rb->in += len;
    return len;
}

uint32_t rb_out(ring_buffer_t *rb, char *buf, uint32_t len)
{
    uint32_t l;
    len = min(len, rb->in - rb->out);
    l = min(len, rb->size - (rb->out & rb->mask));
    memcpy(buf, rb->buf + (rb->out & rb->mask), l);
    memcpy(buf + l, rb->buf, len - l);
    rb->out += len;
    return len;
}
