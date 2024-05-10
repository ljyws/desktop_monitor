#include <desktop_monitor.h>

DesktopMonitor desktop_monitor;

void setup() 
{
  desktop_monitor.init();
  // desktop_monitor.desktop_monitor_gui();
}


void loop() 
{
  // Serial.println("aaaa");
  // desktop_monitor.local_info.get_local_time();
  desktop_monitor.local_info.update();
  // desktop_monitor.local_info.get_city_code();
  // desktop_monitor.local_info.get_city_weater();
  // lv_timer_handler();
  delay(1000);
}

