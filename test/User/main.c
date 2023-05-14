/*!
    \file    main.c
    \brief   led spark with systick

    \version 2016-08-15, V1.0.0, firmware for GD32F4xx
    \version 2018-12-12, V2.0.0, firmware for GD32F4xx
    \version 2020-09-30, V2.1.0, firmware for GD32F4xx
    \version 2022-03-09, V3.0.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2022, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "blink.h"

/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void){
    systick_config();
    rcu_periph_clock_enable(RCU_GPIOE);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOG);
    rcu_periph_clock_enable(RCU_GPIOA);
    gpio_mode_set(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_3);
    gpio_mode_set(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_7);
    gpio_mode_set(GPIOG, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_3);
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_5);
    gpio_output_options_set(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_3);
    gpio_output_options_set(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_7);
    gpio_output_options_set(GPIOG, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_3);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, GPIO_PIN_5);
    gpio_bit_reset(GPIOE,GPIO_PIN_3);
    gpio_bit_reset(GPIOD,GPIO_PIN_7);
    gpio_bit_reset(GPIOG,GPIO_PIN_3);
    gpio_bit_reset(GPIOA,GPIO_PIN_5);
    delay_1ms(500);
    gpio_bit_set(GPIOE,GPIO_PIN_3);
    gpio_bit_set(GPIOD,GPIO_PIN_7);
    gpio_bit_set(GPIOG,GPIO_PIN_3);
    gpio_bit_set(GPIOA,GPIO_PIN_5);
    delay_1ms(500);
    gpio_bit_reset(GPIOE,GPIO_PIN_3);
    gpio_bit_reset(GPIOD,GPIO_PIN_7);
    gpio_bit_reset(GPIOG,GPIO_PIN_3);
    gpio_bit_reset(GPIOA,GPIO_PIN_5);
    
    
    for(int j=1;j<=100000;j++){
            gpio_bit_reset(GPIOE,GPIO_PIN_3);
            delay_1us(2);
            gpio_bit_set(GPIOE,GPIO_PIN_3);
            delay_1us(8);
    }
    gpio_bit_set(GPIOE,GPIO_PIN_3);
    delay_1ms(100);
    for(int j=1;j<=100000;j++){
            gpio_bit_reset(GPIOD,GPIO_PIN_7);
            delay_1us(4);
            gpio_bit_set(GPIOD,GPIO_PIN_7);
            delay_1us(6);
    }
    gpio_bit_set(GPIOD,GPIO_PIN_7);
    delay_1ms(100);
    for(int j=1;j<=100000;j++){
            gpio_bit_reset(GPIOG,GPIO_PIN_3);
            delay_1us(6);
            gpio_bit_set(GPIOG,GPIO_PIN_3);
            delay_1us(4);
    }
    gpio_bit_set(GPIOG,GPIO_PIN_3);
    delay_1ms(100);
    for(int j=1;j<=100000;j++){
            gpio_bit_reset(GPIOA,GPIO_PIN_5);
            delay_1us(8);
            gpio_bit_set(GPIOA,GPIO_PIN_5);
            delay_1us(2);
    }
    gpio_bit_set(GPIOA,GPIO_PIN_5);
    delay_1ms(100);
    gpio_bit_reset(GPIOE,GPIO_PIN_3);
    gpio_bit_reset(GPIOD,GPIO_PIN_7);
    gpio_bit_reset(GPIOG,GPIO_PIN_3);
    gpio_bit_reset(GPIOA,GPIO_PIN_5);
    
    while(1) {
        breathe(GPIOE,GPIO_PIN_3,0,50,2,500);
    }
}
