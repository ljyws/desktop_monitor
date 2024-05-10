#include "network.h"



void NetWork::init(String ssid, String password)
{
	WiFi.mode(WIFI_STA);
	WiFi.setAutoConnect(true);
	Serial.println("");
	Serial.print("Connecting: ");
	Serial.print(ssid.c_str());
	Serial.print(" @");
	Serial.println(password.c_str());

	WiFi.begin(wifi_ssid,wifi_password);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
}
