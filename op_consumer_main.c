#include "k_v_benchmark.h"
#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

static
void process_op(bm_op_t op) {
    // fprintf(stderr, "Received op: %d, key: %"PRIu64"\n", op.type, op.key_hv);
}

int main (void)
{
    void* context = zmq_ctx_new ();
    void* consumer = zmq_socket (context, ZMQ_SUB);
    zmq_connect (consumer, "tcp://localhost:5555");
    zmq_setsockopt(consumer, ZMQ_SUBSCRIBE, NULL, 0);
    fprintf (stderr, "Connected consumer...\n");

    while (1) {
        char buffer[sizeof(bm_op_t)];
        int nbytes = zmq_recv(consumer, buffer, sizeof(bm_op_t), ZMQ_DONTWAIT);
        if (sizeof(bm_op_t) == nbytes) {
            bm_op_t* op_ptr = (bm_op_t*) buffer;
            process_op(*op_ptr);
        }
    }
    return 0;
}