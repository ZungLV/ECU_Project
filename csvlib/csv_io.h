#ifndef CSV_IO_H
#define CSV_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/**
 * @brief   Typedef đơn giản chỉ có hai giá trị "OKAY" và "NOT_OKAY".
 */
typedef enum {
    OKAY,
    NOT_OKAY,
} Std_ReturnType;


/**
 * @brief   Đọc chuỗi PDU (ví dụ "0x3F0 8 03 13 BD 00 00 00 00 00")
 *          từ file CSV với key là "can".
 *
 * @param   key   Chuỗi khóa (chỉ quan tâm "can").
 * @return  Nếu tồn tại dòng bắt đầu bằng "can," thì trả phần sau dấu ',' (malloc’d).
 *          Caller phải free() sau khi dùng. Nếu không tìm thấy hoặc lỗi, trả NULL.
 */
const char* csv_getString(const char* key);


/**
 * @brief   Đọc các thông tin thông qua các cảm biến và động cơ
 *          từ file CSV với key là "temp", "voltage", "current"...
 *
 * @param   key   Chuỗi khóa ("temp", "voltage", "current"...).
 * @return  Nếu tồn tại dòng bắt đầu bằng ""temp,", "voltage,", "current,"...," 
 *          thì trả phần sau dấu ',' (malloc’d) dưới kiểu int.
 *          Caller phải free() sau khi dùng. Nếu không tìm thấy hoặc lỗi, trả NULL.
 */
int csv_getInt(const char* key);


/**
 * @brief   Thay đổi giá trị mong muốn dựa theo key 
 *          (ví dụ với key là "temp" và value là "100" thì sẽ được "temp,100")
 *
 * @param   key     Chuỗi khóa ("temp", "voltage", "current"...).
 * @param   value   Giá trị mong muốn được thay vào    
 */
void csv_setInt(const char* key, int value);



#endif /* CSV_IO_H */