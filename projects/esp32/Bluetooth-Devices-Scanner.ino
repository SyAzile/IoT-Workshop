#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

String DEVICE_NAME = "BT_TEST_01";
bool BT_AVAILABLE = false; 

void setup(){
  Serial.begin(115200);
  Serial.println("ESP32 Bluetooth Scanner");

  #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
    Serial.println("Bluetooth not enabled!");
    return;
  #endif

  #if !defined(CONFIG_BT_SPP_ENABLED)
    Serial.println("Serial Port Profile not available!");
    return;
  #endif

  Serial.println("Bluetooth Configuration: OK!");

  if(SerialBT.begin(DEVICE_NAME))
    BT_AVAILABLE = true;
  else
    Serial.println("Failed to Initialize Bluetooth");
}

void loop(){
  if(!BT_AVAILABLE){
    delay(1000);
    return;
  }

  Serial.println("\nScanning Devices...");

  BTScanResults *btScan = SerialBT.discover(10000);

  if (btScan) {
    int cnt = btScan->getCount();
    Serial.printf("Found %d device(s):\n", cnt);
    
    for (int i = 0; i < cnt; i++) {
      BTAdvertisedDevice *device = btScan->getDevice(i);
      Serial.printf("%s (%s) - %d dBm\n",device->getName().c_str(), device->getAddress().toString().c_str(), device->getRSSI());
    }
  } 
  else
    Serial.println("No Devices Found!!!");

  delay(15000);
}