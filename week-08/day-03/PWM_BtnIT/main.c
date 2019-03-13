#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;
GPIO_InitTypeDef button_handle;

/* pin config: we cannot use the green user LED, because it's not connected to an output compare channel so we use PA15*/
GPIO_InitTypeDef PA15_LED_config;

volatile int counter = 0;
uint32_t tickstart;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_button(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	button_handle.Pin = GPIO_PIN_10;
	button_handle.Pull = GPIO_NOPULL;
	button_handle.Speed = GPIO_SPEED_FAST;
	button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOF, &button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    init_button();
	tickstart = HAL_GetTick();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;	/* this alternate function we need to use TIM2 in output compare mode */
    HAL_GPIO_Init(GPIOA, &PA15_LED_config);

    __HAL_RCC_TIM2_CLK_ENABLE();
    TimHandle.Instance = TIM2;
    TimHandle.Init.Prescaler		= 108 - 1;	/* 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms */
    TimHandle.Init.Period			= 100 - 1;	/* 100 x 0.001 ms = 10 ms = 0.01 s period */
    TimHandle.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode		= TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&TimHandle) */
    HAL_TIM_PWM_Init(&TimHandle);

    sConfig.Pulse = 0;
    /* 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high; our eyes are not able to notice, that it is a vibrating light */
    sConfig.OCMode 		= TIM_OCMODE_PWM1;
    sConfig.OCPolarity 	= TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode 	= TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);

    HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);

    while (1) {
    	uint32_t tickstart = HAL_GetTick();
    	while ((HAL_GetTick() - tickstart) < 1000){
    	}
    	if (counter == 0) {
    		__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, counter);
    	} else {
    		counter -= 10;
    		__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, counter);
    	}
    }
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if ((HAL_GetTick() - tickstart) > 200) {
		counter += 10;
		if (counter >= 100) {
			__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, 100);
		} else {
			__HAL_TIM_SET_COMPARE(&TimHandle, TIM_CHANNEL_1, counter);
		}
	}
}

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}
