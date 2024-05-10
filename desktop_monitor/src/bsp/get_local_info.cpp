#include "get_local_info.h"

void GetLocalInfo::init()
{
    // sntp_set_time_sync_notification_cb(get_local_time);
    // sntp_servermode_dhcp(1);
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2,ntpServer3);
}

void GetLocalInfo::update()
{
    get_local_time();
    get_city_code();
    get_city_weater();
    local_info.tm_hour = timeinfo.tm_hour;
    local_info.tm_min = timeinfo.tm_min;
    local_info.tm_sec = timeinfo.tm_sec;
    local_info.tm_mday = timeinfo.tm_mday;
    local_info.tm_mon = timeinfo.tm_mon+1;
    local_info.tm_year = timeinfo.tm_year + 1900;
    local_info.tm_wday = timeinfo.tm_wday;
    printf("%d 年 %d 月 %d 日 %d:%d:%d \r\n",local_info.tm_year,local_info.tm_mon,local_info.tm_mday,local_info.tm_hour,local_info.tm_min,local_info.tm_sec);
}

void GetLocalInfo::get_city_code()
{
  String URL = "http://wgeo.weather.com.cn/ip?_=" + String(now()); //获得当前ip URL
  HTTPClient http_client;  //创建HTTP客户端
  http_client.begin(this->wifi_client,URL);
  http_client.setUserAgent("Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 Safari/604.1");
  http_client.addHeader("Referer", "http://www.weather.com.cn/");
  int http_code = http_client.GET();
//   Serial.print("Send GET request to URL: ");
//   Serial.println(URL);

  if (http_code == HTTP_CODE_OK)
  {
      String str = http_client.getString();
    //   Serial.println("getCityCode中返回值：\n");
    //   Serial.println(str);
      int id = str.indexOf("id=");
      if (id > -1)
      {
          city_code = str.substring(id + 4, id + 4 + 9);
        //   Serial.println(city_code);
      }
      else
      {
        //   Serial.println("get city code failed！");
      }
  }
  else
  {
    //   Serial.println("failed！");
    //   Serial.println(http_code);
  }
  http_client.end();
}

void GetLocalInfo::get_city_weater()
{

    // String URL = "http://d1.weather.com.cn/dingzhi/" + cityCode + ".html?_="+String(now());//新
    String URL = "http://d1.weather.com.cn/weather_index/" + city_code + ".html?_=" + String(now()); // 原来
    // 创建 HTTPClient 对象
    HTTPClient http_client;
 
    // httpClient.begin(URL);
    http_client.begin(wifi_client, URL); // 使用新方法
 
    // 设置请求头中的User-Agent
    http_client.setUserAgent("Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 Safari/604.1");
    http_client.addHeader("Referer", "http://www.weather.com.cn/");
 
    // 启动连接并发送HTTP请求
    int http_code = http_client.GET();
    // Serial.println("正在获取天气数据");
    // Serial.println(URL);
 
    // 如果服务器响应OK则从服务器获取响应体信息并通过串口输出
    if (http_code == HTTP_CODE_OK)
    {
 
        String str = http_client.getString();
        // Serial.println(str);
        // Serial.println("httpdata=" + str);
        int indexStart = str.indexOf("weatherinfo\":");
        int indexEnd = str.indexOf("};var alarmDZ");
 
        weather_msg.city_DZ = str.substring(indexStart + 13, indexEnd);
 
        indexStart = str.indexOf("dataSK =");
        indexEnd = str.indexOf(";var dataZS");
        weather_msg.data_SK = str.substring(indexStart + 8, indexEnd);
 
        indexStart = str.indexOf("\"f\":[");
        indexEnd = str.indexOf(",{\"fa");
        weather_msg.data_FC = str.substring(indexStart + 5, indexEnd);
 
        // Serial.println("get weather success");
        // Serial.println(weather_msg.city_DZ);
        // Serial.println(weather_msg.data_SK);
        // Serial.println(weather_msg.data_FC);
    }
    else
    {
        // Serial.println("failed");
        // Serial.print(http_code);
    }
    http_client.end();
}


void GetLocalInfo::get_local_time()
{
    if(!getLocalTime(&timeinfo))
    {
        // Serial.println("No time available (yet)");
        return;
    }
    // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

