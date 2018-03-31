#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_rcc.h"
#include "systemclockset.h"

void SystemClock_Config(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq)
{
    RCC_OscInitTypeDef      RCC_OscInitStruct;// Oscillator
    RCC_ClkInitTypeDef      RCC_ClkInitStruct;
    
    /* Enable Power Control clock */
    __HAL_RCC_PWR_CLK_ENABLE();
    
    /* 
    * The voltage scaling allows optimizing the power consumption when the device is 
    * clocked below the maximum system frequency, to update the voltage scaling value 
    * regarding system frequency refer to product datasheet.  
    */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1); 

    
    
}