#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include <stdio.h>
#include "csv_io.h"
#include "Adc.h"
#include <stdint.h>


/**
 * @brief   Lấy dữ liệu về nhiệt độ dựa trên dữ liệu ADC của cảm biến.
 *
 * @param   temp_adc   Dữ liệu nhiệt độ dưới dạng ADC.
 * @param   temp_C     Nhiệt độ (℃) đã được tính toán lại dựa trên ADC.
 * 
 * @return  Trả về "OKAY" nếu hàm thực hiện thành công, ngược lại trả về "NOT_OKAY"
 */
Std_ReturnType IoHwAb_ReadTemp(uint16_t* temp_adc, float* temp_C);


/**
 * @brief   Lấy dữ liệu về điện áp dựa trên dữ liệu ADC của cảm biến.
 *
 * @param   voltage_adc   Dữ liệu điện áp dưới dạng ADC.
 * @param   voltage_V     Điện áp (V) đã được tính toán lại dựa trên ADC.
 * 
 * @return  Trả về "OKAY" nếu hàm thực hiện thành công, ngược lại trả về "NOT_OKAY"
 */
Std_ReturnType IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V);


/**
 * @brief   Lấy dữ liệu về dòng điện dựa trên dữ liệu ADC của cảm biến.
 *
 * @param   current_adc   Dữ liệu dòng điện dưới dạng ADC.
 * @param   current_A     Dòng điện (A) đã được tính toán lại dựa trên ADC.
 * 
 * @return  Trả về "OKAY" nếu hàm thực hiện thành công, ngược lại trả về "NOT_OKAY"
 */
Std_ReturnType IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A);


/**
 * @brief   Lấy dữ liệu về moment xoắn dựa trên dữ liệu ADC của cảm biến.
 *
 * @param   torque_adc    Dữ liệu moment xoắn dưới dạng ADC.
 * @param   torque_Nm     Moment xoắn (N.m) đã được tính toán lại dựa trên ADC.
 * 
 * @return  Trả về "OKAY" nếu hàm thực hiện thành công, ngược lại trả về "NOT_OKAY"
 */
Std_ReturnType IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm);


/**
 * @brief   Lấy dữ liệu về tốc độ động cơ dựa trên dữ liệu ADC của cảm biến.
 *
 * @param   rpm     Tốc độ động cơ (rpm) đã được lấy trực tiếp từ csv.
 * 
 * @return  Trả về "OKAY" nếu hàm thực hiện thành công, ngược lại trả về "NOT_OKAY"
 */
Std_ReturnType IoHwAb_ReadRpm(uint16_t* rpm);




#endif /* IOHWAB_ADC_H */