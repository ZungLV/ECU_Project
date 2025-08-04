#ifndef CAN_H
#define CAN_H

#include <stdio.h>
#include <stdint.h>
#include "csv_io.h"

#define MAX_DATA_BYTES 8

typedef struct
{
    uint32_t canId;
    uint8_t data[MAX_DATA_BYTES];
    uint8_t dlc;
} Can;


void Can_Init(void);

void Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc);

void print_can(Can can_channel);

#endif /* CAN_H */