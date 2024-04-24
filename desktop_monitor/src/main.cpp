#include <Arduino.h>
#include <display/lgfx_config.hpp>

Lgfx_Monitor tft;

void setup() 
{
  tft.init();
  tft.setTextSize((std::max(tft.width(), tft.height()) + 255) >> 8);

  tft.fillScreen(TFT_BLACK);
}
uint32_t count = ~0;
void loop() 
{
  tft.startWrite();
  tft.setRotation(++count & 7);
  tft.setColorDepth((count & 8) ? 16 : 24);

  tft.setTextColor(TFT_WHITE);
  tft.drawNumber(tft.getRotation(), 16, 0);

  tft.setTextColor(0xFF0000U);
  tft.drawString("R", 30, 16);
  tft.setTextColor(0x00FF00U);
  tft.drawString("G", 40, 16);
  tft.setTextColor(0x0000FFU);
  tft.drawString("B", 50, 16);

  tft.drawRect(30,30,tft.width()-60,tft.height()-60,count*7);
  tft.drawFastHLine(0, 0, 10);

  tft.endWrite();
}
