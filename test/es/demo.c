#include "event_scheduler.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
uint8_t DemoEvent1Run(void* pvDemoEventPara)
{
    printf("Demo Event #1 is RUNNING...\n");
    return 0;
}

uint8_t demo_event1_wait_msg(void* msg)
{
    printf("demo event #1 is PENDING...");
    return 1;
}

uint8_t DemoEvent2Run(void* pvDemoEventPara)
{
    printf("Demo Event #2 is RUNNING...\n");
    return 0;
}
uint8_t demo_event2_wait_msg(void* msg)
{
    printf("demo event #2 is PENDING...");
    return 1;
}

int main()
{
    uint32_t uwDemoEventPriority = 0;
    uint32_t uwDemoEventType = 9;
    uint32_t uwDemoItvlMin = 400;
    uint32_t uwDemoItvlMax = 600;
    uint32_t uwDemoEventMemSize = 100;
    EventRegister(uwDemoEventPriority, uwDemoEventType, uwDemoItvlMin, uwDemoItvlMax, uwDemoEventMemSize, DemoEvent1Run);

    uwDemoEventPriority = 1;
    uwDemoEventType = 8;
    uwDemoItvlMin = 200;
    uwDemoItvlMax = 300;
    uwDemoEventMemSize = 200;
    EventRegister(uwDemoEventPriority, uwDemoEventType, uwDemoItvlMin, uwDemoItvlMax, uwDemoEventMemSize, DemoEvent2Run);

    EventRun();
    //system("pause");
}