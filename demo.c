// --------------------------------------------------------------------------
// Demo program for the ST7735-library
//
// Author: Bernhard Bablok
//
// The code is based on work from Gavin Lyons, see
// https://github.com/gavinlyonsrepo/pic_16F18346_projects
//
// https://github.com/bablokb/pico-st7735
// --------------------------------------------------------------------------
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hw.h"
#include "tst_funcs.h"
#include "ST7735_TFT.h"

#define TFT_ENABLE_BLACK
#define TFT_ENABLE_TEST1
// ---------------------------------------------------------------------------
// hardware-specific intialization
// SPI_* constants from CMakeLists.txt or user.h

void init_hw() {
  stdio_init_all();
  spi_init(SPI_PORT, 1000000);                // SPI with 1Mhz
  gpio_set_function(SPI_RX, GPIO_FUNC_SPI);
  gpio_set_function(SPI_SCK,GPIO_FUNC_SPI);
  gpio_set_function(SPI_TX, GPIO_FUNC_SPI);
  tft_spi_init();
}

// ---------------------------------------------------------------------------
// main loop

int main() {
  init_hw();
  for (size_t i = 0; i < 10; i++) {
    printf("ST7735 TFT Display.. %d starting at 10\n", i);
    sleep_ms(1000);
  }
#ifdef TFT_ENABLE_BLACK
  TFT_BlackTab_Initialize();
  printf("BlackTab\n");
#elif defined(TFT_ENABLE_GREEN)
  TFT_GreenTab_Initialize();
  printf("GreenTab\n");
#elif defined(TFT_ENABLE_RED)
  TFT_RedTab_Initialize();
  printf("RedTab\n");
#elif defined(TFT_ENABLE_GENERIC)
  TFT_ST7735B_Initialize();
  printf("Generic\n");
#endif
  setTextWrap(true);
  TEST_DELAY1();
  fillScreen(ST7735_BLACK);
  printf("not found but dw \n");

#if defined(ENABLE_TEST1)
  printf("Running Test1\n");
  Test1();
#endif
#if defined(ENABLE_TEST1A)
  printf("Running Test1A\n");
  Test1A();
#endif
#if defined(ENABLE_TEST2)
  printf("Running Test2\n");
  Test2();
#endif
#if defined(ENABLE_TEST3)
  printf("Running Test3\n");
  Test3();
#endif
#if defined(ENABLE_TEST4)
  printf("Running Test4\n");
  Test4();
#endif
#if defined(ENABLE_TEST5)
  printf("Running Test5\n");
  Test5();
#endif
#if defined(ENABLE_TEST6)
  printf("Running Test6\n");
  Test6();
#endif
#if defined(ENABLE_TEST7)
  printf("Running Test7\n");
  Test7();
#endif
#if defined(ENABLE_TEST8)
  printf("Running Test8\n");
  Test8();
#endif
#if defined(ENABLE_TEST9)
  printf("Running Test9\n");
  Test9();
#endif
#if defined(ENABLE_TEST9A)
  printf("Running Test9A\n");
  Test9A();
#endif

#if defined(TFT_ENABLE_TEXT)
  #if defined(ENABLE_TESTR) && defined(TFT_ENABLE_ROTATE)
  for (size_t i = 0; i < 4; i++) {
    setRotation(i);
  #endif
    fillScreen(ST7735_BLACK);
    drawText(10, 10, "Test over!", ST7735_WHITE, ST7735_BLACK, 1);
    drawFastHLine(0,0,80,ST7735_CYAN);
    drawFastHLine(0,25,80,ST7735_CYAN);
    drawFastVLine(0,0,25,ST7735_CYAN);
    drawFastVLine(80,0,25,ST7735_CYAN);
  #if defined(ENABLE_TESTR) && defined(TFT_ENABLE_ROTATE)
    TEST_DELAY1();
  }
  #endif
#endif
  while(1);
  return 0;
}
