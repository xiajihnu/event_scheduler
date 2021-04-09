#include "timing_manage.h"

uint32_t TimingIntervalAlloc(xScheduleEventInfo* pxTimingInfomation)
{
    xScheduleEventInfo *pxTimingInfo = pxTimingInfomation;
    uint32_t uwItvlMin = pxTimingInfomation->uwIntervalMin;
    uint32_t uwItvlMax = pxTimingInfomation->uwIntervalMax;

    return (uwItvlMin + uwItvlMax) >> 1;
}