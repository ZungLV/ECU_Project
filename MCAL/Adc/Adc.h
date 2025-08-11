#ifndef ADC_H
#define ADC_H

#include <stdio.h>
#include <stdint.h>
#include "csv_io.h"

enum {
    Channel_Adc_temp,
    Channel_Adc_voltage,
    Channel_Adc_current,
    Channel_Adc_torque,
    Channel_Adc_rpm
};

void Adc_Init(void);

/**
 * @brief   Đọc dữ liệu từ các cảm biến các thông tin (temp, voltage, current, torque, rpm).
 *
 * @param   channelId   Các kênh ADC mà ta mong muốn đọc được:
 *                      Channel_Adc_temp,
 *                      Channel_Adc_voltage,
 *                      Channel_Adc_current,
 *                      Channel_Adc_torque,
 *                      Channel_Adc_rpm.
 * 
 * @return  Trả về dữ liệu đọc được của kênh tương ứng dưới kiểu số nguyên
 */
uint16_t Adc_ReadChannel(uint8_t channelId);


#endif /* ADC_H */