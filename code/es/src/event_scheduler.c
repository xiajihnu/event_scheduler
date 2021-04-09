#include <math.h>
#include <stdlib.h>
#include "event_scheduler.h"
#include "timing_manage.h"

xEventNode *g_pxEventList = NULL;

uint8_t EventInsertByFIFO(xEventNode *pxNewEventNode)
{
    xEventNode *pxEventNode = pxNewEventNode;
    xEventNode *pxTmpEvent = EVENT_LIST_HEAD(g_pxEventList);
    if (NULL == pxEventNode)
    {
        return 1;
    }

    if (NULL == pxTmpEvent)
    {
        g_pxEventList = pxEventNode;
        return 0;
    }
    while (pxTmpEvent->pxNextEvent != NULL)
    {
        pxTmpEvent = pxTmpEvent->pxNextEvent;
    }
    pxEventNode->pxPrevEvent = pxTmpEvent;
    pxTmpEvent->pxNextEvent = pxEventNode;

    return 0;
}

uint32_t EventIdAlloc()
{
    return rand();
}

uint8_t EventRegister(uint8_t ucPriority, EventType EventType, uint32_t uwItvlMin, uint32_t uwItvlMax, \
                      uint32_t uwEventMemSize, uint8_t(*pvEventRunCallBack)())
{
    uint32_t uwItvl = 0;
    xScheduleEventInfo xScheInfo;
    xEvent *pxEvent = NULL;
    xEventNode* pxEventNode = NULL;

    /* 封装成具体的Event函数 */
    xScheInfo.ucPeriodicFlag = 1;
    xScheInfo.ucStartTimeAlignFlag = 0;
    xScheInfo.uwIntervalMax = uwItvlMax;
    xScheInfo.uwIntervalMin = uwItvlMin;
    uwItvl = TimingIntervalAlloc(&xScheInfo);
    pxEvent = EventCreate(EventType, uwItvlMin, uwItvlMax, uwItvl, uwEventMemSize, pvEventRunCallBack);

    if (NULL == pxEvent)
    {
        printf("Register Failed.");
    }

    pxEventNode = malloc(sizeof(xEventNode));
    pxEventNode->uwEventId = EventIdAlloc();
    pxEventNode->ucEventPriority = ucPriority;
    pxEventNode->pxNextEvent = NULL;
    pxEventNode->pxPrevEvent = NULL;
    pxEventNode->pxEvent = pxEvent;
    EventInsertByFIFO(pxEventNode);

    return 0;
}

uint8_t EventRemove(xEventNode* pxEventNode)
{
    xEventNode *pxDeleteEvent = pxEventNode;

    if (pxEventNode == NULL)
    {
        printf("Delete Event Error!");
        return 1;
    }
    if (NULL == pxEventNode->pxPrevEvent)
    {
        g_pxEventList = pxEventNode->pxNextEvent;
        pxEventNode->pxNextEvent = NULL;
    }
    else if (NULL == pxEventNode->pxNextEvent)
    {
        pxEventNode->pxPrevEvent->pxNextEvent = NULL;
        pxEventNode->pxPrevEvent = NULL;
    }
    else
    {
        pxEventNode->pxPrevEvent->pxNextEvent = pxEventNode->pxNextEvent;
        pxEventNode->pxNextEvent->pxPrevEvent = pxEventNode->pxPrevEvent;
    }

    EventDelete(pxEventNode->pxEvent);
    printf("EventNode %d delete successfully.\n");
    free(pxEventNode);
}

uint8_t EventCmpById(void* pvSrcEventPara, void* pvDstEventPara)
{
    xEventNode *pxEvent = pvSrcEventPara;
    uint32_t *pxEventId = pvDstEventPara;

    return pxEvent->uwEventId == *pxEventId;
}

uint8_t EventNodeMatch(uint8_t(*pvEventCmp)(void*, void*), void* pvSrcEventPara, void* pvDstEventPara)
{
    return pvEventCmp(pvSrcEventPara, pvDstEventPara);
}

uint8_t EventSearch(uint8_t(*pvEventCmp)(void*, void*), void* pvSrcEventPara, void* pvDstEventPara)
{
    return 0;
}

uint8_t EventRun()
{
    xEvent *pxEvent = NULL;
    xEventNode *pxTmpEventNode = NULL;
    if (EVENT_LIST_EMPTY(g_pxEventList))
    {
        return 0;
    }
    while (1)//应修改为(EventList)非空闲
    {
        //对所有Event的顺序按照优先级重排
        //code...

        pxTmpEventNode = EVENT_LIST_HEAD(g_pxEventList);
        
        while ((NULL != pxTmpEventNode) && (NULL != pxTmpEventNode->pxEvent))
        {
            pxEvent = pxTmpEventNode->pxEvent;
            pxTmpEventNode->event_state = pxEvent->pfEventRun(pxEvent);

            pxTmpEventNode = pxTmpEventNode->pxNextEvent;
        }
    }

    return 0;
}

uint8_t msg_parse(void* msg)
{
    return 0;
}

uint8_t event_scheduler_top(void* msg)
{
    msg_parse(msg);
    while (1)//internal msg_queue is not empty
    {

    }
    return 0;
}