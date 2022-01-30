#ifndef MyLoRa_h
#define MyLoRa_h

#if (ARDUINO > 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SPI.h>
#include <LoRa.h>


class MyLoRa {
  public:

    // Constructor
    MyLoRa (int lora_band, int lora_sck_pin, int lora_miso_pin, int lora_mosi_pin, int lora_ss_pin, int lora_rst_pin, int lora_di00_pin);

    // Methods
    void sendMsg            (String msg);
    bool checkReceive       ();
    void setSF              (int sf);
    void setBW              (int bw);
    void setCRC             (bool crc);
    void setSW              (byte sw);
    void setTXPOWER         (int txpw);
    int getSF               ();
    int getBW               ();
    bool getCRC             ();
    byte getSW              ();
    int getTXPOWER          ();
    String getLastMessage   ();
    int getLastMessageSize  ();
    int getLastMessageRSSI  ();
    float getLastMessageSNR ();

  private:
    int   _setting_spreading_factor   = 11;
    int   _setting_bandwidth          = 125E3;
    byte  _setting_syncword           = 0x37;
    bool  _setting_crc                = true;
    int   _setting_tx_power           = 17;

    String _lastMessage               = "";
    int _lastMessageSize              = 0;
    int _lastMessageRSSI              = 0;
    float _lastMessageSNR             = 0;

};

#endif
