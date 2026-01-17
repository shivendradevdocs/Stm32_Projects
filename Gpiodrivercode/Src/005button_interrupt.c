/*
 * 005button_interrupt.c
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
    memset(&GpioLed,0,sizeof(GpioLed));
    memset(&GpioBtn,0,sizeof(GpioBtn));
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
    GpioBtn.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IT_FT;
//    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed  = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU; // IMPORTANT

    GPIO_Init(&GpioBtn);


    //IRQ Configuration
    GPIO_IRQPriorityConfig(IRQ_NO_EXTI1,NVIC_IRQ_PRI15);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI1,ENABLE);


    while (1)
    {
        /* Active-LOW button */

    }
}


void EXTI1_IRQHandler(void){

	GPIO_IRQHandling(GPIO_PIN_NO_1);
	GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);


}
