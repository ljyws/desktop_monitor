#ifndef __GET_LOCAL_INFO_H__
#define __GET_LOCAL_INFO_H__

#include <HTTPClient.h>
#include <TimeLib.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "sntp.h"


class GetLocalInfo
{
public:

  String city_code = "101280601";
  const char* ntpServer1 = "ntp.aliyun.com";
  const char* ntpServer2 = "ntp2.aliyun.com";
  const char* ntpServer3 = "time.nist.gov";
  long  gmtOffset_sec = 28800;//时区偏移：8*60*60
  int   daylightOffset_sec = 0;
  // char* time_zone = "CET-1CEST,M3.5.0,M10.5.0/3";

  struct tm timeinfo;

  WiFiUDP udp;
  WiFiClient wifi_client;

  typedef struct 
  {
      String city_DZ;
      String data_SK;
      String data_FC;
  }weather_msg_t;
  weather_msg_t weather_msg = {{""}, {""}, {""}};

  typedef struct
  {
    int	tm_sec;
    int	tm_min;
    int	tm_hour;
    int	tm_mday;
    int	tm_mon;
    int	tm_year;
    int	tm_wday;
    int	tm_yday;
    int	tm_isdst;
    String City;
  }local_info_t;
  
  local_info_t local_info;
  void init();
  void update();
  void get_city_code();
  void get_city_weater();
  void get_local_time();
  void send_ntp_packet(IPAddress &address);

};



#endif
