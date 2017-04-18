# Key-Value store benchmark utilities

## Dependencies

* ZeroMQ, http://zeromq.org/

## op_consumer_main.c
It is a subscriber process which receives operations from another process.

gcc -std=gnu11 op_consumer_main.c -lzmq -o consumer
