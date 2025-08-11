#ifndef PWM_H
#define PWM_H

#include <stdio.h>
#include <stdint.h>
#include "csv_io.h"

enum {
    Channel_Pwm_0 = 0,
    Channel_Pwm_1,
    Channel_Pwm_2    
};

void Pwm_Init(void);

void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty);


#endif /* PWM_H */