#pragma once

#include <stdint.h>

typedef uint32_t EventType;

typedef struct xEvent
{
    uint8_t  ucEventType;
    uint32_t uwEventItvlMin;
    uint32_t uwEventItvlMax;
    uint32_t uwEventItvl;

    uint8_t(*pfEventRun)(void* pvArg);

}xEvent;

xEvent  *EventCreate(EventType EventType, uint32_t uwItvlMin, uint32_t uwItvlMax, \
                     uint32_t uwItvl, uint32_t uwEventMemSize, uint8_t(*pvEventRunCallBack)());

uint8_t EventDelete(xEvent *pxEvent);


uint8_t EventInfoPrint(xEvent * pxEventInfomation);