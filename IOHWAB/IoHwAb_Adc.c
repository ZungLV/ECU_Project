#include "IoHwAb_Adc.h"

Std_ReturnType IoHwAb_ReadTemp(uint16_t* temp_adc, float* temp_C)
{
    if(!temp_adc || !temp_C)
    {
        return NOT_OKAY;
    }

    *temp_adc = Adc_ReadChannel(Channel_Adc_temp);
    *temp_C = (*temp_adc) * 200.0 / 4095;
    return OKAY;
}


Std_ReturnType IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V)
{
   if(!voltage_adc || !voltage_V)
    {
        return NOT_OKAY;
    }    

    *voltage_adc = Adc_ReadChannel(Channel_Adc_voltage);
    *voltage_V = (*voltage_adc) * 60.0 / 4095;
    return OKAY;
}


Std_ReturnType IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A)
{
   if(!current_adc || !current_A)
    {
        return NOT_OKAY;
    }    
    
    *current_adc = Adc_ReadChannel(Channel_Adc_current);
    *current_A = (*current_adc) * 50.0 / 4095;
    return OKAY;
}


Std_ReturnType IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm)
{
   if(!torque_adc || !torque_Nm)
    {
        return NOT_OKAY;
    }      

    *torque_adc = Adc_ReadChannel(Channel_Adc_torque);
    *torque_Nm = (*torque_adc) * 120.0 / 4095;
    return OKAY;    
}


Std_ReturnType IoHwAb_ReadRpm(uint16_t* rpm)
{
   if(!rpm)
    {
        return NOT_OKAY;
    }

    *rpm = csv_getInt("rpm");
    return OKAY;
}