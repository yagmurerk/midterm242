/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_host.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

I2S_HandleTypeDef hi2s3;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

void TIMER3_Init(void)
{
	// bilge yagmur erkasap
	//asciiname = 1176, ascii surname = 743, asciitotal = 1919 , timernumber = 1 , arrnumber = 65535 , duration = 22290, ledpin = 15 //


	RCC  -> APB1ENR |= RCC_APB1ENR_TIM3EN // timer3 açıldı

			;
	TIM3 -> ARR = 65535 ; // ARRNUMBER ayarlandı


	TIM3 -> PSC = 2 ; // Prescale set 2 ayarlandı


	TIM3 -> CR1 |= TIM_CR1_OPM ; // timer değişince cr1 0 ve 1 arasinda //


	TIM3 -> CNT = 0 ; // COUNTERIN BAŞLANGIÇ DEĞERİ 0
}
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */



    int duration=22290;
    int timernumber=1;

    TIM3  ->   CR1 = 1 ; // cr1 1 ile başlatıyoruz

	RCC   ->   AHB1ENR |= RCC_AHB1ENR_GPIODEN; // pin tanımı

    GPIOD ->   MODER |= GPIO_MODER_MODE15_0; // 15. led tanımı

    TIMER3_Init();

    // while döngü




    while ( TIM3 -> CR1 == 1 ) // devamlı timer artış
 	    {

    	TIM3 -> CNT = TIM3 -> CNT + timernumber ; // COUNT timer number ölçüsünde ARTIYOR


    	while ( TIM3 -> CNT == 22290 ) // timer durationa ulaşınca, count tekrar 1 e geliyor ve led yanıyor.
    	{
    		TIM3 -> CNT = 1 ; // count 1 e ayarlandı
    		GPIOD  ->  BSRR |= GPIO_BSRR_BS_15  ; // CR1 DURUMUNDA 15.LED YANIYOR

 	    }

 	    }

    }
  /* USER CODE END 1 */

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
}
  */


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
