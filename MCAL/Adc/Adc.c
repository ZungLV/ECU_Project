#include "Adc.h"

void Adc_Init(void)
{
    printf("All Adc channels have been initialized\n");
}

uint16_t Adc_ReadChannel(uint8_t channelId)
{
    int value = 0;
    
    switch (channelId) 
    {
    case Channel_Adc_temp:
        value = csv_getInt("temp");
        break;

    case Channel_Adc_voltage:
        value = csv_getInt("voltage");
        break;

    case Channel_Adc_current:
        value = csv_getInt("current");
        break;

    case Channel_Adc_torque:
        value = csv_getInt("torque");
        break;

    case Channel_Adc_rpm:
        value = csv_getInt("rpm");
        break;

    default:
        printf("Ivalid channel\n");
        break;
    }

    return value;
    
}