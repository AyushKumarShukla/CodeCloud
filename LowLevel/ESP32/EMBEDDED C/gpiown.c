#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//Absolute Addresses 
#define GPIO_OUT_W1TS_REG 0x3FF44008 
#define GPIO_OUT_W1TC_REG 0x3FF4400C
#define GPIO_ENABLE_REG   0x3FF44020
#define PIN 18
#define DELAY_MS 500

void app_main(void)
{	
	volatile uint32_t* w1ts_reg   = (volatile uint32_t*) GPIO_OUT_W1TS_REG;
	volatile uint32_t* w1tc_reg   = (volatile uint32_t*) GPIO_OUT_W1TC_REG;
	volatile uint32_t* enable_reg = (volatile uint32_t*) GPIO_ENABLE_REG;

	// GPIO_ENABLE_REGISTER
	//31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 <-- Indices
	//0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 0 0 0 1 0 0 0 0 0 <-- Data (sets GPIO5 enable)
	//enables the appropriate GPIO PIN
	*enable_reg = ( 1 << PIN );
	while(1)
	{
		*w1ts_reg = ( 1 << PIN );
		vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
		
		*w1tc_reg = ( 1 << PIN );
		vTaskDelay(pdMS_TO_TICKS(DELAY_MS));
	}

}
