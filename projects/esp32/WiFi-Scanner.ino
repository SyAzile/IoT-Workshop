#include "WiFi.h"

const char* encryptionType(wifi_auth_mode_t type) {
  switch (type) {
    case WIFI_AUTH_OPEN:
      return "Open";
    case WIFI_AUTH_WEP:
      return "WEP";
    case WIFI_AUTH_WPA_PSK:
      return "WPA";
    case WIFI_AUTH_WPA2_PSK:
      return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA/WPA2";
    case WIFI_AUTH_WPA2_ENTERPRISE:
      return "WPA2-Enterprise";
    case WIFI_AUTH_WPA3_PSK:
      return "WPA3";
    case WIFI_AUTH_WPA2_WPA3_PSK:
      return "WPA2/WPA3";
    case WIFI_AUTH_WAPI_PSK:
      return "WAPI";
    default:
      return "Unknown";
  }
}

void setup(){
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println("Scanning WiFi...");
}

void loop(){
  int ntCount = WiFi.scanNetworks();

  if(ntCount == 0)
    Serial.println("No Networks Found!!!");
  else{
    Serial.printf("Found %d networks.\n", ntCount);

    for(int i = 0; i < ntCount; i++)
      Serial.printf("%s | Signal: %d dBm | Channel: %d | Security: %s\n", WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i), encryptionType(WiFi.encryptionType(i)));

    Serial.println();
  }

  WiFi.scanDelete();
  delay(10000);
}