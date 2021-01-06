#include "ringbuffer/ring_buffer.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    char buf[1024];
    char output[1024];
    ring_buffer_t rb;
    rb_init(&rb, buf, 1024);
    uint32_t len = rb_in(&rb,"input",5);
    printf("input data len is %d\n",len);
    len = rb_out(&rb,output,5);
    printf("output data len is %d\n",len);
    printf("size:%u out:%u in:%u\n",rb.size,rb.out,rb.in);
}
