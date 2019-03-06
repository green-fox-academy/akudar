#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* create a config structure */
GPIO_InitTypeDef LEDS;
GPIO_InitTypeDef push_button;


int main(void)
{
    HAL_Init();
    BSP_LED_Init(LED1);

    __HAL_RCC_GPIOF_CLK_ENABLE();

    LEDS.Pin = GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_7;
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;
    LEDS.Pull = GPIO_NOPULL;
    LEDS.Speed = GPIO_SPEED_HIGH;

    push_button.Pin = GPIO_PIN_8;
    push_button.Mode = GPIO_MODE_INPUT;
    push_button.Pull = GPIO_PULLUP;
    push_button.Speed = GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOF, &LEDS);
    HAL_GPIO_Init(GPIOF, &push_button);

    while (1) {
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_Delay(500);

        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
        HAL_Delay(500);

        if (!HAL_GPIO_ReadPin(GPIOF, push_button.Pin)) {
        	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
        } else {
        	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
        }
    }
}
