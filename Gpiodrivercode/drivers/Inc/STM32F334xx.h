/*
 * STM32F334xx.h
 *
 *  Created on: 27-Dec-2025
 *      Author: shivendrarai
 */

#ifndef STM32F334XX_H_
#define STM32F334XX_H_

#include<stdint.h>

#define __vo volatile



/**********************************START:Processor Specific Details **********************************/
/*
 * ARM Cortex M4x Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0          ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2          ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3          ( (__vo uint32_t*)0xE000E10c )


/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 			((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1			((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2  		((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0XE000E18C)


/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR 	((__vo uint32_t*)0xE000E400)


#define NO_PR_BITS_IMPLEMENTED			4
// Base address of flash and sram
#define FLASH_BASEADDR              0x08000000UL
#define SRAM_BASEADDR               0x20000000UL
#define SYSTEM_MEMORY_BASEADDR      0x1FFFD800UL   /* System ROM (bootloader) */


/* ================= PERIPHERAL ROOT ================= */

#define PERIPH_BASE    0x40000000UL

/* ================= BUS BASE ADDRESSES ================= */
#define APB1PERI_BASE  PERIPH_BASE
#define APB2PERI_BASE  0x40010000UL
#define AHB1PERI_BASE  0x40020000UL
#define AHB2PERI_BASE  0x48000000UL

/* ================= AHB1 PERIPHERALS ================= */
#define DMA1_BASEADDR               (AHB1PERIPH_BASE + 0x0000UL)  /* 0x40020000 */
#define FLASH_REG_BASEADDR          (AHB1PERIPH_BASE + 0x2000UL)  /* 0x40022000 */
#define CRC_BASEADDR                (AHB1PERIPH_BASE + 0x3000UL)  /* 0x40023000 */


/* ================= AHB2 PERIPHERALS (GPIO) ================= */
#define GPIOA_BASEADDR              (AHB2PERI_BASE)  /* 0x48000000 */
#define GPIOB_BASEADDR              (AHB2PERI_BASE + 0x0400UL)  /* 0x48000400 */
#define GPIOC_BASEADDR              (AHB2PERI_BASE + 0x0800UL)  /* 0x48000800 */
#define GPIOD_BASEADDR              (AHB2PERI_BASE + 0x0C00UL)  /* 0x48000C00 */


/* ================= APB2 PERIPHERALS ================= */
#define SYSCFG_BASEADDR             (APB2PERI_BASE + 0x0000UL)
#define EXTI_BASEADDR               (APB2PERI_BASE + 0x0400UL)

#define TIM1_BASEADDR               (APB2PERI_BASE + 0x2C00UL)
#define SPI1_BASEADDR               (APB2PERI_BASE + 0x3000UL)
#define USART1_BASEADDR             (APB2PERI_BASE + 0x3800UL)

#define TIM15_BASEADDR              (APB2PERI_BASE + 0x4000UL)
#define TIM16_BASEADDR              (APB2PERI_BASE + 0x4400UL)
#define TIM17_BASEADDR              (APB2PERI_BASE + 0x4800UL)


/* ================= ADC (SEPARATE DOMAIN) ================= */

#define ADC1_BASEADDR               0x50000000UL



// BASE address of peripheral  which is on APB1


#define TIM2_BASEADDR               (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASEADDR               (APB1PERIPH_BASE + 0x0400UL)
#define TIM6_BASEADDR               (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASEADDR               (APB1PERIPH_BASE + 0x1400UL)

#define RTC_BASEADDR                (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASEADDR               (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASEADDR               (APB1PERIPH_BASE + 0x3000UL)

#define SPI2_BASEADDR               (APB1PERIPH_BASE + 0x3800UL)
#define USART2_BASEADDR             (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASEADDR             (APB1PERIPH_BASE + 0x4800UL)

#define I2C1_BASEADDR               (APB1PERIPH_BASE + 0x5400UL)  /* ONLY I2C */

#define PWR_BASEADDR                (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASEADDR                (APB1PERIPH_BASE + 0x7400UL)
#define CEC_BASEADDR                (APB1PERIPH_BASE + 0x7800UL)


/* ================= CORE SYSTEM (NOT ON APB/AHB) ================= */

#define NVIC_BASEADDR               0xE000E100UL
#define SCB_BASEADDR                0xE000ED00UL
#define SYSTICK_BASEADDR            0xE000E010UL
#define DWT_BASEADDR                0xE0001000UL



/* ================= Peripheral register definition  ================= */

typedef struct
{
    volatile uint32_t MODER;    /* 0x00: GPIO port mode register */
    volatile uint32_t OTYPER;   /* 0x04: GPIO port output type register */
    volatile uint32_t OSPEEDR;  /* 0x08: GPIO port output speed register */
    volatile uint32_t PUPDR;    /* 0x0C: GPIO port pull-up/pull-down register */
    volatile uint32_t IDR;      /* 0x10: GPIO port input data register */
    volatile uint32_t ODR;      /* 0x14: GPIO port output data register */
    volatile uint32_t BSRR;     /* 0x18: GPIO port bit set/reset register */
    volatile uint32_t LCKR;     /* 0x1C: GPIO port configuration lock register */
    volatile uint32_t AFR[2];     /* 0x20: GPIO alternate function low register and high */
    volatile uint32_t BRR;      /* 0x28: AHB2 bit reset register (F3 only) */
} GPIO_TypeDef;



#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASEADDR)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASEADDR)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASEADDR)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASEADDR)



#define RCC_BASEADDR   0x40021000UL

typedef struct
{
    volatile uint32_t CR;         /* 0x00 Clock control register */
    volatile uint32_t CFGR;       /* 0x04 Clock configuration register */
    volatile uint32_t CIR;        /* 0x08 Clock interrupt register */
    volatile uint32_t APB2RSTR;   /* 0x0C APB2 peripheral reset */
    volatile uint32_t APB1RSTR;   /* 0x10 APB1 peripheral reset */
    volatile uint32_t AHBENR;     /* 0x14 AHB peripheral clock enable */
    volatile uint32_t APB2ENR;    /* 0x18 APB2 peripheral clock enable */
    volatile uint32_t APB1ENR;    /* 0x1C APB1 peripheral clock enable */
    volatile uint32_t BDCR;       /* 0x20 Backup domain control */
    volatile uint32_t CSR;        /* 0x24 Control/status register */
    volatile uint32_t AHBRSTR;    /* 0x28 AHB peripheral reset */
    volatile uint32_t CFGR2;      /* 0x2C Clock configuration register 2 */
    volatile uint32_t CFGR3;      /* 0x30 Clock configuration register 3 */
} RCC_TypeDef;



typedef struct
{
	__vo uint32_t IMR;    /*!< Give a short description,          	  	    Address offset: 0x00 */
	__vo uint32_t EMR;    /*!< TODO,                						Address offset: 0x04 */
	__vo uint32_t RTSR;   /*!< TODO,  									     Address offset: 0x08 */
	__vo uint32_t FTSR;   /*!< TODO, 										Address offset: 0x0C */
	__vo uint32_t SWIER;  /*!< TODO,  									   Address offset: 0x10 */
	__vo uint32_t PR;     /*!< TODO,                   					   Address offset: 0x14 */

}EXTI_RegDef_t;

typedef struct
{
    volatile uint32_t CFGR1;     /* 0x00: Configuration register 1 */
    volatile uint32_t CFGR2;
    volatile uint32_t EXTICR[4]; /* 0x04: Configuration register 2 */
//    volatile uint32_t EXTICR1;   /* 0x08: EXTI configuration register 1 */
//    volatile uint32_t EXTICR2;   /* 0x0C: EXTI configuration register 2 */
//    volatile uint32_t EXTICR3;   /* 0x10: EXTI configuration register 3 */
//    volatile uint32_t EXTICR4;   /* 0x14: EXTI configuration register 4 */
    volatile uint32_t CFGR3;     /* 0x18: Configuration register 3 */
    volatile uint32_t CFGR4;     /* 0x1C: Configuration register 4 */
} SYSCFG_TypeDef;

#define RCC   ((RCC_TypeDef *) RCC_BASEADDR)
#define EXTI ((EXTI_RegDef_t *)EXTI_BASEADDR)
#define SYSCFG ((SYSCFG_TypeDef *)SYSCFG_BASEADDR)
// Clock enable macros for GPIOx

#define GPIOA_PCLK_EN()  (RCC->AHBENR|=(1<<17))
#define GPIOB_PCLK_EN()  (RCC->AHBENR|=(1<<18))
#define GPIOC_PCLK_EN()  (RCC->AHBENR|=(1<<19))
#define GPIOD_PCLK_EN()  (RCC->AHBENR|=(1<<20))

#define GPIOA_PCLK_DI()  (RCC->AHBENR &= ~(1U << 17))
#define GPIOB_PCLK_DI()  (RCC->AHBENR &= ~(1U << 18))
#define GPIOC_PCLK_DI()  (RCC->AHBENR &= ~(1U << 19))
#define GPIOD_PCLK_DI()  (RCC->AHBENR &= ~(1U << 20))
// Clock enable macros for I2C

#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1U << 21))
#define I2C1_PCLK_DI()     (RCC->APB1ENR &= ~(1U << 21))

// Clock enable macros for SPIx

#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1U << 12))
#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1U << 12))

#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1U << 14))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1U << 14))

// Clock enable macros for USARTx
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1U << 14))
#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~(1U << 14))

#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1U << 17))
#define USART2_PCLK_DI()   (RCC->APB1ENR &= ~(1U << 17))

#define USART3_PCLK_EN()   (RCC->APB1ENR |= (1U << 18))
#define USART3_PCLK_DI()   (RCC->APB1ENR &= ~(1U << 18))


// Clock enable macros for SYSCFG

#define SYSCFG_PCLK_EN()   (RCC->APB2ENR |= (1U << 0))
#define SYSCFG_PCLK_DI()   (RCC->APB2ENR &= ~(1U << 0))


#define GPIOA_REG_RESET()      do{(RCC->AHBRSTR |=(1<<17)); (RCC->AHBRSTR &=~(1<<17));}while(0)
#define GPIOB_REG_RESET()      do{(RCC->AHBRSTR |=(1<<18)); (RCC->AHBRSTR &=~(1<<18));}while(0)
#define GPIOC_REG_RESET()      do{(RCC->AHBRSTR |=(1<<19)); (RCC->AHBRSTR &=~(1<<19));}while(0)
#define GPIOD_REG_RESET()      do{(RCC->AHBRSTR |=(1<<20)); (RCC->AHBRSTR &=~(1<<20));}while(0)
//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET         RESET
#define FLAG_SET 			SET



#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:0)



//    <--------------------------------IRQ No--------------------------------->

#define IRQ_NO_EXTI0 		6
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51
#define IRQ_NO_SPI4
#define IRQ_NO_I2C1_EV     31
#define IRQ_NO_I2C1_ER     32
#define IRQ_NO_USART1	    37
#define IRQ_NO_USART2	    38
#define IRQ_NO_USART3	    39
#define IRQ_NO_UART4	    52
#define IRQ_NO_UART5	    53
#define IRQ_NO_USART6	    71

/*
 * macros for all the possible priority levels
 */
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI15    15




#endif /* STM32F334XX_H_ */
