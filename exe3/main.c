#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_PIN_G = 26;
const int BTN_PIN_R = 28;

int main() {
  stdio_init_all();
  
  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);
  
  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  int estado_LED_G = 0;
  int estado_LED_R = 0;


  while (true) {
    if (!gpio_get(BTN_PIN_G)) {
      printf("Verde apertado  ");
      estado_LED_G = !estado_LED_G;
      printf("estado verde: %d\n",estado_LED_G);
      gpio_put(LED_PIN_G,estado_LED_G);
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
    
    if (!gpio_get(BTN_PIN_R)) {
      printf("Verm apertado  ");
      estado_LED_R = !estado_LED_R;
      printf("estado verm: %d \n ",estado_LED_R);
      gpio_put(LED_PIN_R,estado_LED_R);
      while (!gpio_get(BTN_PIN_R)) {
      };
    }
  }
}
