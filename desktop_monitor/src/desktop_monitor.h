#ifndef __DESKTOP_MONITOR_H__
#define __DESKTOP_MONITOR_H__

#include <stdio.h>
#include <Arduino.h>

#include "bsp/network.h"
#include "bsp/get_local_info.h"
#include "desktop_monitor_config.h"

#include "lvgl.h"
#include "display/lv_porting/lv_port_disp.h"
#include "display/lv_porting/lv_port_indev.h"
#include <../.pio/libdeps/esp32-s3-devkitc-1/lvgl/src/core/lv_obj.h>

class DesktopMonitor
{
public:

  lv_obj_t *gui;
  NetWork wifi;
  GetLocalInfo local_info;
  void init();
  void init_log();
  void desktop_monitor_gui();


};



#endif
