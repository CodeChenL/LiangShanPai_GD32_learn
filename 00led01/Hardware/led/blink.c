#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "blink.h"
void breathe(uint32_t gpio_periph, uint32_t pin,uint32_t sduty,uint32_t period,uint32_t step,uint32_t count){
    for(int i=sduty;i<=period;i+=step){
        int set=period-i;
        int reset=i;
        for(int j=1;j<=count;j++){
            gpio_bit_reset(gpio_periph,pin);
            delay_1us(reset);
            gpio_bit_set(gpio_periph,pin);
            delay_1us(set);
        }
    }
    for(int i=sduty;i<=period;i+=step){
        int reset=period-i;
        int set=i;
        for(int j=1;j<=count;j++){
            gpio_bit_reset(gpio_periph,pin);
            delay_1us(reset);
            gpio_bit_set(gpio_periph,pin);
            delay_1us(set);
        }
    }
}

        