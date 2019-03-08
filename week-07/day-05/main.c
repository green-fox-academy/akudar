#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* necessary include files */
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"

static void Error_Handler(void);
static void SystemClock_Config(void);
void draw_circle(unsigned int x, unsigned int y);
void game(char* input);

RNG_HandleTypeDef rng;

int main(void)
{

    HAL_Init();
    SystemClock_Config();
    rng.Instance = RNG;
	__HAL_RCC_RNG_CLK_ENABLE();
    HAL_RNG_Init(&rng);

    /* initializing LCD */
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_YELLOW);
    BSP_LCD_Clear(LCD_COLOR_BLUE);

    BSP_TS_Init(480, 272);
    TS_StateTypeDef ts_state;

    char text[] = "Let's play a game! Are you ready?";
    unsigned int y = 2;
    unsigned int bool = 0;

	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTMAGENTA);

    while (1) {

    	BSP_TS_GetState(&ts_state);
    	if (ts_state.touchDetected > 0) {
    		game(text);
    	}
    	y += 27;

    	if (y > 250) {
    		y = 0;
    	}
    	if (bool == 0) {
    		BSP_LCD_Clear(LCD_COLOR_YELLOW);
    		BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
    		BSP_LCD_DisplayStringAt(0, y, text, CENTER_MODE);
    		bool = 1;
    	} else {
    		BSP_LCD_Clear(LCD_COLOR_BLUE);
    		BSP_LCD_SetBackColor(LCD_COLOR_YELLOW);
    		BSP_LCD_DisplayStringAt(0, y, text, CENTER_MODE);
    		bool = 0;
    	}
    	HAL_Delay(1000);
    }
}

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

void draw_circle(unsigned int x, unsigned int y)
{
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_FillCircle(x, y, 30);
}

void game(char* input)
{
	unsigned int counter = HAL_RNG_GetRandomNumber(&rng) % 10 + 1;
	TS_StateTypeDef second_ts;
	unsigned int timer = 0;
	unsigned int touchX = 0;
	unsigned int touchY = 0;

	while(counter != 0) {
		BSP_LCD_Clear(LCD_COLOR_BLUE);
		sprintf(input, "%u", counter);
		BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
		BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
		BSP_LCD_DisplayStringAt(0,126, input, CENTER_MODE);
		counter--;
		HAL_Delay(1000);
		BSP_LCD_Clear(LCD_COLOR_BLUE);
	}

    unsigned int randomX = HAL_RNG_GetRandomNumber(&rng) % 420 + 30;
    unsigned int randomY = HAL_RNG_GetRandomNumber(&rng) % 212 + 30;
	draw_circle(randomX, randomY);

	BSP_TS_GetState(&second_ts);
	while (second_ts.touchDetected == 0) {
		timer++;
		BSP_TS_GetState(&second_ts);
		touchX = *second_ts.touchX;
		touchY = *second_ts.touchY;
		HAL_Delay(10);
	}

	while (counter != -1) {
		BSP_TS_GetState(&second_ts);
		switch (second_ts.touchDetected) {
		case 1:
			BSP_LCD_Clear(LCD_COLOR_BLUE);
			break;
		case 2:
			sprintf(input, "%d,%d", timer/100, timer%100);
			BSP_LCD_DisplayStringAt(0,0, input, LEFT_MODE);
			sprintf(input, "(%d,%d)", randomX, randomY);
			BSP_LCD_DisplayStringAt(0,0, input, RIGHT_MODE);
			sprintf(input, "(%d,%d)", touchX, touchY);
			BSP_LCD_DisplayStringAt(0,0, input, CENTER_MODE);
			break;
		case 3:
			counter = -1;
		}
	}
	game(input);
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){}
#endif
