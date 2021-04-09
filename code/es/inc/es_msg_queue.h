#pragma once
#include <stdint.h>
#include <queue>
using namespace std;

struct es_internal_msg
{
    uint8_t es_msg_type;
    uint8_t es_event_id;

    void* msg_para;
};

typedef struct es_internal_msg es_msg;

struct msg_queue
{
    queue<es_msg> msg_queue;
    uint8_t(*push)(es_msg);
    es_msg (*pop)();
    uint8_t(*empty)();
};

typedef msg_queue msg_q;

