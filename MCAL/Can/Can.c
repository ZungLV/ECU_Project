#include "Can.h"

void Can_Init(void)
{
    printf("All Can channels have been initialized\n");
}

void Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc)
{
    /* Gọi csv_lib để lấy chuỗi Can (ví dụ "0x3F0 8 03 13 BD ...") */
    char *can_frame = csv_getString("can");

    /* Kiểm tra xem chuỗi can có rỗng không */
    if(!can_frame)
    {
        printf("Lỗi không có frame mới hoặc không mở được file\n");
        return;
    }

    /* 1) Lấy CAN ID */
    char *token = strtok(can_frame, " ");
    
    if (!token) {
        printf("Lỗi không nhận được can id\n");
        free(can_frame);
        return;
    }

    /* Thiết lập lại errno để tránh trùng với lỗi trước đó nếu có */
    errno = 0;
    unsigned long idParsed = strtoul(token, NULL, 0);
    if (errno != 0) {
        perror("Không nhận được id");
        free(can_frame);
        return;
    }
    *canId = (uint32_t)idParsed;

    /* 2) Lấy DLC */
    token = strtok(NULL, " ");
    if (!token) {
        printf("Lỗi không nhận được dlc\n");
        free(can_frame);
        return;
    }
    errno = 0;
    unsigned long dlcParsed = strtoul(token, NULL, 10);
    if (errno != 0 || dlcParsed > MAX_DATA_BYTES) {
        perror("Không nhận được dlc hay dlc vượt quá độ dài cho phép");
        free(can_frame);
        return;
    }
    *dlc = (uint8_t)dlcParsed;

    /* 3) Lấy dữ liệu byte */
    for (uint8_t i = 0; i < *dlc; i++) {
        token = strtok(NULL, " ");
        if (!token) {
            printf("Gặp lỗi trong việc truy xuất data\n");
            data[i] = 0;
            continue;
        }
        errno = 0;
        unsigned long byteVal = strtoul(token, NULL, 16);
        if (errno != 0 || byteVal > 0xFF) {
            perror("Data can không hợp lệ");
            free(can_frame);
            return;
        }
        data[i] = (uint8_t)byteVal;
    }

    free(can_frame);
}

void print_can(Can can_channel)
{
    printf("Can id: %#X\n", can_channel.canId);
    printf("Can dlc: %u\n", can_channel.dlc);
    printf("Can data: ");
    for (uint8_t i = 0; i < can_channel.dlc; i++) 
    {
    printf("%02X ", can_channel.data[i]);
    }
    printf("\n");
}