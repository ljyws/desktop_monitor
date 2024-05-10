#include "desktop_monitor.h"


void DesktopMonitor::init()
{
  delay(1000);
  Serial.begin(115200);
  init_log();

  //system log
  Serial.println("[desktop-monitor] author: ljyws");
  Serial.println("[desktop-monitor] https://xyljy.top");

  //wifi init`
  Serial.println("[desktop-monitor] wifi: init....");
  wifi.init(wifi.wifi_ssid,wifi.wifi_password);
  local_info.init();
  //lvgl init
  Serial.println("[desktop-monitor] display-init....");
  // lv_init();
  // lv_port_disp_init();
  // lv_port_indev_init();
}

void DesktopMonitor::init_log()
{
  const char desktop_monitor_init_logo[]{
    "      __  _ \r\n"                   
    "     / / (_)_  ___      _______\r\n"   
    "    / / / / / / / | /| / / ___/\r\n"   
    "   / / / / /_/ /| |/ |/ (__  ) \r\n"   
    "  /_/_/ /__, / |__/|__/____/  \r\n"   
    "   /___//____/                 \r\n"   
  };
  Serial.println(desktop_monitor_init_logo);
}

void DesktopMonitor::desktop_monitor_gui()
{
  static lv_style_t dm_style;
  lv_style_init(&dm_style);
  lv_style_set_bg_color(&dm_style,lv_palette_main(LV_PALETTE_BLUE));

  lv_obj_add_style(lv_scr_act(),&dm_style,LV_STATE_DEFAULT);
}