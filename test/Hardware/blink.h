#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>

void breathe(uint32_t gpio_periph, uint32_t pin,uint32_t sduty,uint32_t period,uint32_t step,uint32_t count);