/*
 * externalbutton.c
 *
 *  Created on: 17-Jan-2026
 *      Author: shivendrarai
 */


#include <STM32F334xx.h>
#include <stm32f334xx_gpio_driver.h>
#include <string.h>



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

    /* ================= BUTTON CONFIG (PA1 / A1) ================= */
    GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_1;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IN;
//    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU; // IMPORTANT

    GPIO_Init(&GpioBtn);

    while (1)
    {
        /* Active-LOW button */
        if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_1) == 0)
        {
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_SET);
        }
        else
        {
            GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, GPIO_PIN_RESET);
        }
    }
}
