#include "bsp_led.h"
void led_gpio_config(void){
    /* 开启GPIOD时钟 */
    BSP_RCU_AHB1EN |= (1<<3);
    /* 配置GPIOD模式 */
    BSP_GPIOD_CTL &= ~(0x03 << (2*7));
    BSP_GPIOD_CTL |= (0x01 << (2*7));
    
    BSP_GPIOD_PUD &= ~(0x03 << (2*7));
    BSP_GPIOD_PUD |= (0x00 << (2*7));
    /* 配置GPIOD输出 */
    BSP_GPIOD_OMODE &= ~(0x01 << 7);
    BSP_GPIOD_OSPD &= ~(0x03 << (2*7));
    BSP_GPIOD_OSPD |= (0x03 << (2*7));
}