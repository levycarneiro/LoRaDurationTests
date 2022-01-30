
// Hardware = Heltec ESP32 LoRa v2 board.

#include "MyLoRa.h"
const int LORA_SCK_PIN = 5;
const int LORA_MISO_PIN = 19;
const int LORA_MOSI_PIN = 27;
const int LORA_SS_PIN = 18;
const int LORA_RST_PIN = 14;
const int LORA_DI00_PIN = 26;
const int LORA_BAND = 915E6;
MyLoRa myLora = MyLoRa (LORA_BAND, LORA_SCK_PIN, LORA_MISO_PIN, LORA_MOSI_PIN, LORA_SS_PIN, LORA_RST_PIN, LORA_DI00_PIN);

int sf;
float bw;
int supportedBandwidths[10] = {7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3, 250E3, 500E3};
unsigned long ts_start;
unsigned long ts_end;
unsigned long ts_diff;

void setup() {
  Serial.begin (115200);
  Serial.println ("Starting duration tests.");
  Serial.println ("");
  Serial.println ("");

  Serial.println ("| Spreading Factor | Bandwidth (KHz) | Duration (ms) |");
  Serial.println ("| --- | --- | --- |");

  for (sf = 6; sf<=12; sf++) {

    myLora.setSF (sf);

    for (int i=0; i<10; i++) {
      bw = supportedBandwidths[i];

      myLora.setBW (bw);
      Serial.print ("| " + String(sf));

      bw = bw / 1000;
      Serial.print (" | ");
      Serial.print (bw);

      // Send message and measure duration.
      ts_start = millis();
      myLora.sendMsg("Hello");
      ts_end = millis();
      ts_diff = ts_end - ts_start;

      Serial.println(" | " + String(ts_diff) + " |");

      delay(2000);
    }
  }
}

void loop () {
}
