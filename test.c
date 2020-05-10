//C Headers
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//Components
#include "SRA18.h"

void blink_task(void *arg)
{
	adc1_channel_t channel[4] = {ADC_CHANNEL_7,ADC_CHANNEL_6,ADC_CHANNEL_0,ADC_CHANNEL_3};

int adc_reading[4];

void sensor_task(void *arg)
{

	gpio_set_direction(LED_1,GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_2,GPIO_MODE_OUTPUT);	

	while(1)
	{for(int i =0;i<4;i++)
		{
			adc_reading[i] = adc1_get_raw(channel[i]);

		gpio_set_level(LED_1,adc_reading[i]);	//Set LED1 ON
		gpio_set_level(LED_2,adc_reading[i]);	//Set LED2 ON       


    		vTaskDelay(1000 / 10);	//Wait for 1000ms
		


		gpio_set_level(LED_1,adc_reading[i]);	//Set LED1 OFF
		gpio_set_level(LED_2,adc_reading[i]);	//Set LED2 OFF
       

		vTaskDelay(1000 / 10);	//Wait for 1000ms
	}
	
}

void app_main()
{
	/*
		Basic Function for task creation
	*/

	xTaskCreate(&blink_task,"blink task",4096,NULL,1,NULL);
}
