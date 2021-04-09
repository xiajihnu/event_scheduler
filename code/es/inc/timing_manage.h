#pragma once
#include <stdint.h>

typedef struct xScheduleEventInfomation
{
    uint8_t  ucPeriodicFlag;
    uint8_t  ucStartTimeAlignFlag;
    uint32_t uwIntervalMin;
    uint32_t uwIntervalMax;

}xScheduleEventInfo;

uint32_t TimingIntervalAlloc(xScheduleEventInfo*);