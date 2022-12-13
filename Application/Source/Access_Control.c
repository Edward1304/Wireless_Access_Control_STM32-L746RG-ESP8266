/*
 * Access_Control.c
 *
 *  Created on: Dec 2, 2022
 *      Author: Edward Fabian
 */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define R1_PORT GPIOA
#define R1_PIN GPIO_PIN_7

#define R2_PORT GPIOA
#define R2_PIN GPIO_PIN_6

#define R3_PORT GPIOA
#define R3_PIN GPIO_PIN_5

#define R4_PORT GPIOA
#define R4_PIN GPIO_PIN_4

#define C1_PORT GPIOA
#define C1_PIN GPIO_PIN_3

#define C2_PORT GPIOA
#define C2_PIN GPIO_PIN_2

#define C3_PORT GPIOA
#define C3_PIN GPIO_PIN_1

#define C4_PORT GPIOA
#define C4_PIN GPIO_PIN_0


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t key;

char read_keypad (void)
{
	/* Make ROW 1 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (R1_PORT, R1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (R2_PORT, R2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
		return '1';
	}

	if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
		return '2';
	}

	if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
		return '3';
	}

	if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
		return 'A';
	}


	HAL_GPIO_WritePin (R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R2_PORT, R2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
		return '4';
	}

	if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
		return '5';
	}

	if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
		return '6';
	}

	if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
		return 'B';
	}


	/* Make ROW 3 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R2_PORT, R2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R3_PORT, R3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin (R4_PORT, R4_PIN, GPIO_PIN_SET);

	if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
		return '7';
	}

	if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
		return '8';
	}

	if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
		return '9';
	}

	if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
		return 'C';
	}


	/* Make ROW 4 LOW and all other ROWs HIGH */
	HAL_GPIO_WritePin (R1_PORT, R1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R2_PORT, R2_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R3_PORT, R3_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin (R4_PORT, R4_PIN, GPIO_PIN_RESET);

	if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
		return '*';
	}

	if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
		return '0';
	}

	if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
		return '#';
	}

	if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
	{
		while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
		return 'D';
	}

}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

	lcd_init ();
	lcd_send_cmd (0x80);
	lcd_send_string ("Clave: ");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		key = read_keypad ();

		if (key!=0x01)
		{
		lcd_send_cmd (0x85);
		lcd_send_data (1234);
		scroll_string ((uint8_t *) "Bienvenido Edward, puedes Seguir   ", 150, left);
		}
		if (key!=0x01)
				{
				lcd_send_cmd (0x85);
				lcd_send_data != (1234);
				scroll_string ((uint8_t *) "Acceso Denegado  ", 150, left);
				}






  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


