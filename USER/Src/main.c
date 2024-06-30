
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "FreeRTOSApp.h"
#include "./USMART/usmart.h"
#include "./MALLOC/malloc.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/SRAM/sram.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* LED状态设置函数 */
void led_set(uint8_t sta)
{
    LED1(sta);
}

/* 函数参数调用测试函数 */
void test_fun(void (*ledset)(uint8_t), uint8_t sta)
{
    ledset(sta);
}

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7); /* 设置时钟,168Mhz */
    delay_init(168);                    /* 延时初始化 */
    usart_init(115200);                 /* 串口初始化为115200 */
    usmart_dev.init(84);                /* USMART初始化 */
    led_init();                         /* LED初始化 */
    lcd_init();                         /* LCD初始化 */
    sram_init();                        /* SRAM初始化 */
    my_mem_init(SRAMIN);                /* 初始化内部SRAM内存池 */
    my_mem_init(SRAMEX);                /* 初始化外部SRAM内存池 */
    my_mem_init(SRAMCCM);               /* 初始化内部CCM内存池 */

    freeRTOS_Init();
}
