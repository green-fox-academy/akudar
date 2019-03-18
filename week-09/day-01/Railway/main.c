#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* create the configuration structs */
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_handle;

volatile uint16_t tim_val = 0;
volatile int counter = 0;

enum barrier
{
	OPEN,
	SECURING,
	SECURED,
	OPENING
};

volatile enum barrier crossing = OPEN;

#define UART_PUTCHAR int __io_putchar(int ch)

#define TIM_HIGHER
//#define EXTI_HIGHER

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_uart(void)
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);
}

void init_user_button(void)
{
	__HAL_RCC_GPIOI_CLK_ENABLE(); /* enable the GPIOI clock */

	user_button_handle.Pin = GPIO_PIN_11; /* the pin is the 11 */
	/* We know from the board's datasheet that a resistor is already installed externally for this button
	 (so it's not floating), we don't want to use the internal pull feature */
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST; /* port speed to fast */
	/* Here is the trick: our mode is interrupt on rising edge */
	user_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &user_button_handle);

	/* we don't need to explicitly call the HAL_NVIC_SetPriorityGrouping function,
	 * because the grouping defaults to NVIC_PRIORITYGROUP_2:
	 * HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);
	 */

	/* assign the intermediate priority to our interrupt line */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_timer(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	HAL_TIM_Base_DeInit(&timer_handle);
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1;
	timer_handle.Init.Period = 5000 - 1;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);

#ifdef TIM_HIGHER
	/* assign the highest priority to our interrupt line */
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
#endif
#ifdef EXTI_HIGHER
	/* assign the lowest priority to our interrupt line */
	HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
#endif
	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);

	init_uart();
	init_user_button();
	init_timer();

	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {

	}
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (crossing == OPEN) {
		crossing = SECURING;
		printf("SECURING\n");
		counter = 0;
	} else if (crossing == SECURED) {
		crossing = OPENING;
		printf("OPENING\n");
		counter = 0;
	}
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (crossing == OPEN && counter % 2 == 0) {
		BSP_LED_Toggle(LED_GREEN);
	} else if (crossing == SECURING) {
		BSP_LED_Toggle(LED_GREEN);
		if (counter == 10) {
			crossing = SECURED;
			printf("SECURED\n");
			counter = 0;
		}
	} else if (crossing == SECURED) {
		BSP_LED_Off(LED_GREEN);
	} else if (crossing == OPENING) {
		BSP_LED_Toggle(LED_GREEN);
		if (counter == 12) {
			crossing = OPEN;
			printf("OPEN\n");
			counter = 0;
		}
	}
	counter++;
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
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

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
