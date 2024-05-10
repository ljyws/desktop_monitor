#ifndef __WIFI_H__
#define __WIFI_H__

#include <WiFi.h>
#include <HTTPClient.h>
#include "desktop_monitor_config.h"
 
class NetWork
{
public:

	String wifi_ssid = "xyljy";
	String wifi_password = "ljy559..";

	void init(String ssid, String password);
};

extern NetWork wifi;

#endif