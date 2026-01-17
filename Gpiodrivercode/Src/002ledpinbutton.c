/*
 * 002ledpinbutton.c
 *
 *  Created on: 29-Dec-2025
 *      Author: shivendrarai
 */




//#include <STM32F334xx.h>
//#include <stm32f334xx_gpio_driver.h>
//
//
//
//int main(void){
//	GPIO_Handle_t GpioLed;
//    GPIO_Handle_t GpioBtn;
//
//	GpioLed.pGPIOx=GPIOA;
//	GpioLed.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
//	GpioLed.GPIO_PinConfig.GPIO_PinMode=GPIO_MODE_OUT;
//	GpioLed.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
//	GpioLed.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_PP;
//	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
//
//
//	/* ================= BUTTON CONFIG (PC13) ================= */
//	GpioBtn.pGPIOx = GPIOC;
//    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
//    GpioBtn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IN;
//    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
//    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
//
//    GPIO_PeriClockControl(GPIOC, ENABLE);
//    GPIO_Init(&GpioBtn);
//
//	GPIO_PeriClockControl(GPIOA,ENABLE);
//
//
//
//
//	GPIO_Init(&GpioLed);
//
//
//	while(1){
//
//
//
//        /* Read button using IDR */
//        if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0)
//        {
//            /* Button pressed */
//            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
//        }
//        else
//        {
//            /* Button released */
//            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);
//        }
//
//	}
//}
//
#include "stm32f334xx.h"
#include "stm32f334xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}
int main(void)
{
    GPIO_Handle_t GpioLed;
    GPIO_Handle_t GpioBtn;

    /* ================= LED CONFIG (PA5) ================= */
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
    GpioLed.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioLed);

    /* ================= BUTTON CONFIG (PC13) ================= */
    GpioBtn.pGPIOx = GPIOC;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD; // OK for PC13

    GPIO_PeriClockControl(GPIOC, ENABLE);
    GPIO_Init(&GpioBtn);

    while (1)
    {
        if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0)
        {
        	delay();
        	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
        }

    }
}
