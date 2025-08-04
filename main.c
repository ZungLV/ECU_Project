#include <stdio.h>
#include "csv_io.h"
#include "Adc.h"
#include "Can.h"
#include "Dio.h"
#include "Pwm.h"

Can Can_Channel_0;

int main() {
    Dio_Init();
    Dio_WriteChannel(Channel_Dio_0,1);
    Pwm_Init();
    Pwm_SetDutyCycle(Channel_Pwm_0,50);
    Adc_Init();
    uint16_t rpm = Adc_ReadChannel(Channel_Adc_rpm);
    printf("%d\n",rpm);
    Can_Init();
    Can_Receive(&Can_Channel_0.canId, Can_Channel_0.data, &Can_Channel_0.dlc);
    print_can(Can_Channel_0);

    return 0;
}