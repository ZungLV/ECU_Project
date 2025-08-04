#include "Pwm.h"

void Pwm_Init(void)
{
    printf("All Pwm channels have been initialized\n");
}

void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty)
{
    csv_setInt("duty", duty);
}