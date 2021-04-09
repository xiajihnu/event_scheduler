#ifndef MSG_QUEUE_H
#define MSG_QUEUE_H
#include <stdint.h>

typedef struct msg_node
{
    uint8_t msg_type;
    //...more parameter.

    struct msg_node *msg_next;

} msg_node;

typedef struct msg_queue
{
    msg_node *msg_head;
    msg_node *msg_tail;
}msg_queue;

uint8_t push(msg_queue *, msg_node *);
msg_node * pop(msg_queue *);
uint8_t empty(msg_queue *);
uint8_t msg_queue_init(msg_queue *);

#endif
