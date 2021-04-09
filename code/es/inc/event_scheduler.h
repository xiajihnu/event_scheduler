#pragma once
#include "event.h"
#include <stdio.h>

#define EVENT_LIST_HEAD(x)  (x)
#define EVENT_LIST_EMPTY(x) ((NULL == (x)) ||(NULL == ((x)->pxEvent)))
//#define FOR_EACH_EVENT(pxEvent, EventList) { \
//            pxEvent = EVENT_LIST_HEAD(EventList);\
//            while()
//}

typedef struct xNode
{
    uint32_t uwEventId;
    uint8_t  ucEventPriority;
    uint8_t  event_state;
    struct xNode *pxPrevEvent;
    struct xNode *pxNextEvent;
    xEvent     *pxEvent;
}xEventNode;



uint8_t EventRegister(uint8_t ucPriority, EventType EventType, uint32_t uwItvlMin, uint32_t uwItvlMax, \
    uint32_t uwEventMemSize, uint8_t(*pvEventRunCallBack)());

uint8_t EventRun();

uint8_t event_scheduler_top(void* msg);