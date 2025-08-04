#ifndef DIO_H
#define DIO_H

#include <stdio.h>
#include <stdint.h>
#include "csv_io.h"

enum {
    Channel_Dio_0 = 0,
    Channel_Dio_1,
    Channel_Dio_2    
};

void Dio_Init(void);

void Dio_WriteChannel(uint8_t channelId, uint8_t level);


#endif /* DIO_H */