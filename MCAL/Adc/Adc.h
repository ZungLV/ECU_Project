#ifndef ADC_H
#define ADC_H

#include <stdio.h>
#include <stdint.h>
#include "csv_io.h"

enum {
    Channel_Adc_temp = 0,
    Channel_Adc_voltage,
    Channel_Adc_current,
    Channel_Adc_torque,
    Channel_Adc_rpm,
};

void Adc_Init(void);

uint16_t Adc_ReadChannel(uint8_t channelId);


#endif /* ADC_H */