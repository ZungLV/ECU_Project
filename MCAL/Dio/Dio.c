#include "Dio.h"

void Dio_Init(void)
{
    printf("All Dio channels have been initialized\n");
}

void Dio_WriteChannel(uint8_t channelId, uint8_t level)
{
    if(level==0 || level==1)
    {
        csv_setInt("direction", level);
        return;
    }

    printf("Invalid level, only 0 and 1\n");
}