#include <stdio.h>
#include "csv_io.h"
#include "Can.h"
#include "Dio.h"
#include "Pwm.h"
#include "Adc.h"
#include "IoHwAb_Adc.h"

Can Can_Channel_0;

int main() {


    // Chặng 1///////////////////////////////////////////////////////////////////
    // Dio_Init();
    // Dio_WriteChannel(Channel_Dio_0,1);
    // Pwm_Init();
    // Pwm_SetDutyCycle(Channel_Pwm_0,50);
    // Adc_Init();
    // uint16_t rpm = Adc_ReadChannel(Channel_Adc_rpm);
    // printf("%d\n",rpm);
    // Can_Init();
    // Can_Receive(&Can_Channel_0.canId, Can_Channel_0.data, &Can_Channel_0.dlc);
    // print_can(Can_Channel_0);
    /////////////////////////////////////////////////////////////////////////////


    // Chặng 2///////////////////////////////////////////////////////////////////
    uint16_t adc_count;
    float temp_C;
    IoHwAb_ReadTemp(&adc_count, &temp_C);
    printf("ADC = %u, Nhiệt độ = %.2f°C\n", adc_count, temp_C);


    uint16_t adc_voltage;
    float voltage_V;
    IoHwAb_ReadVoltage(&adc_voltage, &voltage_V);
    printf("Vcc = %.2f V\n", voltage_V);


    uint16_t adc_current;
    float current_A;
    IoHwAb_ReadCurrent(&adc_current, &current_A);
    printf("I = %.2f A\n", current_A);


    uint16_t adc_torque;
    float torque_Nm;
    IoHwAb_ReadTorque(&adc_torque, &torque_Nm);
    printf("Torque = %.2f Nm\n", torque_Nm);


    uint16_t rpm;
    IoHwAb_ReadRpm(&rpm);
    printf("RPM = %u\n", rpm);
    /////////////////////////////////////////////////////////////////////////////


    return 0;
}