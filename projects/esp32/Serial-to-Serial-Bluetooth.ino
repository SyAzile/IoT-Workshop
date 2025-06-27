#include "BluetoothSerial.h"

bool BT_AVAILABLE = false;
String DEVICE_NAME = "DEVICE-01";

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  
  #if defined(CONFIG_BT_ENABLED) && defined(CONFIG_BLUEDROID_ENABLED) && defined(CONFIG_BT_SPP_ENABLED)
    if (SerialBT.begin(DEVICE_NAME)) {
      BT_AVAILABLE = true;
      SerialBT.deleteAllBondedDevices();
      Serial.printf("Device \"%s\" is available to connect.\n", DEVICE_NAME.c_str());
    } 
    else
      Serial.println("Bluetooth failed to start");
  
  #else
    Serial.println("Bluetooth not configured!!!");

  #endif  
}

void loop() {
  if (Serial.available()){
    String data = Serial.readString();
    data = "PC: " + data;

    if(BT_AVAILABLE){
      SerialBT.print(data);
      Serial.print(data);
    } 
    else
      Serial.print("Failed to send message!!!");
  }

  if (BT_AVAILABLE && SerialBT.available()) {
    String btData = SerialBT.readString();
    Serial.println(DEVICE_NAME + ": " + btData);
  }
}