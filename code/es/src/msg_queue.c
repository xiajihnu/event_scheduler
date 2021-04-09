#include "msg_queue.h"

uint8_t empty(msg_queue *msg_q)
{
    return (msg_q->msg_head == msg_q->msg_tail);
}

uint8_t push(msg_queue *msg_q, msg_node *msg)
{
    msg_q->msg_tail->msg_next = msg;
    msg_q->msg_tail = msg;
    return 0;
}

msg_node * pop(msg_queue * msg_q)
{
    msg_node *first_msg = NULL;
    if (!empty(msg_q))
    {
        first_msg = msg_q->msg_head;
        msg_q->msg_head = msg_q->msg_head->msg_next;
        return first_msg;
    }

    return NULL;
}