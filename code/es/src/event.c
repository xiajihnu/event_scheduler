#include <stdio.h>
#include <stdlib.h>
#include "event.h"

uint8_t EventInfoPrint(xEvent * pxEventInfomation)
{
    xEvent *pxEventNode = pxEventInfomation;

    printf("*****************Event Infomation*****************\n");
    printf("Event Type\t : %d\n", pxEventNode->ucEventType);
    printf("Interval\t : %d\n", pxEventNode->uwEventItvl);
    printf("***************Event Infomation Done**************\n\n");
    return 0;
}

/*
 * Create event and initial parameters.
 */
xEvent * EventCreate(EventType EventType, uint32_t uwItvlMin, uint32_t uwItvlMax, \
                     uint32_t uwItvl, uint32_t uwEventMemSize, uint8_t(*pvEventRunCallBack)())
{
    xEvent * pxEvent = NULL;
    pxEvent = malloc(uwEventMemSize);
    if (NULL == pxEvent)
    {
        printf("Event Register Failed.\n");
        return NULL;
    }

    /* 应该封装进Event的初始化函数 */
    pxEvent->ucEventType = EventType;
    pxEvent->uwEventItvlMin = uwItvlMin;
    pxEvent->uwEventItvlMax = uwItvlMax;
    //pxEventNode->uwAnchorPoint = TimingAnchorPointAlloc(NULL);//计算部分放在EventScheduler.c，赋值放在Event.c

    pxEvent->uwEventItvl = uwItvl;

    pxEvent->pfEventRun = pvEventRunCallBack;
    EventInfoPrint(pxEvent);

    return pxEvent;
}

uint8_t  EventDelete(xEvent *pxEvent)
{
    /* Delete all task and free memory first. */
    //Delete(TaskList);

    /* Free memory */
    free(pxEvent);
    printf("Event memory free successfully.");
    return 0;
}