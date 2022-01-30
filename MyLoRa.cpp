#include "MyLoRa.h"

MyLoRa::MyLoRa (int lora_band, int lora_sck_pin, int lora_miso_pin, int lora_mosi_pin, int lora_ss_pin, int lora_rst_pin, int lora_di00_pin) {

  SPI.begin (lora_sck_pin, lora_miso_pin, lora_mosi_pin, lora_ss_pin);   // Initiating SPI communication
  LoRa.setPins (lora_ss_pin, lora_rst_pin, lora_di00_pin);               // Setting LoRa pins

  if (!LoRa.begin(lora_band)) {                                          // Initiating LoRa radio
    Serial.println("Error when trying to initialize LoRa.");
    while (1);
  }

  // Setting our own defaults if we want something different from the LoRa.h library's defaults.
  //setSF (11);
  //setBW (62.5E3);
  //setSW (0x44);

  LoRa.receive();                                                        // Enables receiving packets
}

//##########################################################################################
// Set functions

void MyLoRa::setSF (int sf) {
  if (sf >= 6 && sf <= 12) {
    LoRa.setSpreadingFactor (sf);
    _setting_spreading_factor = sf;
  }
}

void MyLoRa::setBW (int bw) {
  if (bw == 7.8E3 || bw == 10.4E3 || bw == 15.6E3 || bw == 20.8E3 || bw == 31.25E3 || bw == 41.7E3 || bw == 62.5E3 || bw == 125E3 || bw == 250E3 || bw == 500E3) {
    LoRa.setSignalBandwidth(bw);
    _setting_bandwidth = bw;
  }
}

void MyLoRa::setCRC (bool crc) {
  if (crc) {
    LoRa.enableCrc();
  } else {
    LoRa.disableCrc();
  }
  _setting_crc = crc;
}

void MyLoRa::setSW (byte sw) {
  LoRa.setSyncWord (sw);
  _setting_syncword = sw;
}

void MyLoRa::setTXPOWER (int txpwr) {
  if (txpwr >= 2 && txpwr <= 20) {
    LoRa.setTxPower (txpwr);
    _setting_tx_power = txpwr;
  }
}

//##########################################################################################
// Get functions

String MyLoRa::getLastMessage () {
  return _lastMessage;
}
int MyLoRa::getSF () {
  return _setting_spreading_factor;
}
int MyLoRa::getBW () {
  return _setting_bandwidth;
}
bool MyLoRa::getCRC () {
  return _setting_crc;
}
byte MyLoRa::getSW () {
  return _setting_syncword;
}
int MyLoRa::getTXPOWER () {
  return _setting_tx_power;
}

//##########################################################################################
// Send / Receive functions

bool MyLoRa::checkReceive () {

  int packetSize = LoRa.parsePacket();                                   // Attempts to read packet

  if (packetSize > 1) {
    _lastMessageSize = packetSize;

    String received = "";
    while (LoRa.available()) {
      received += (char) LoRa.read();                                   // Store the packet's data in a string
    }
    _lastMessage = received;

    _lastMessageRSSI = LoRa.packetRssi();
    _lastMessageSNR  = LoRa.packetSnr();

    return true;
  } else {
    return false;
  }
}

void MyLoRa::sendMsg (String msg) {
  LoRa.beginPacket();
  LoRa.print(msg);
  LoRa.endPacket();
}
