#include "pxt.h"

#include "OneWire.h"

using namespace pxt;

enum class Pins {
  P0 =  3,
  P1 =  2,
  P2 =  1,
  P3 =  4,
  P4 =  5,
  P5 =  17,
  P6 =  12,
  P7 =  11,
  P8 =  18,
  P9 =  10,
  P10 = 6,
  P11 = 26,
  P12 = 20,
  P13 = 23,
  P14 = 22,
  P15 = 21,
  P16 = 16,
  P19 = 0,
  P20 = 30
};

namespace DS18B20 {
  OneWire * mOneWire = NULL;
  
  //%
  void init(Pins pin) {
    if (mOneWire != NULL) {
      delete mOneWire;
    }
  
    mOneWire = new OneWire((PinName) pin);
  
    mOneWire->init();
  }
  
  //%
  float get_temp() {
    if (mOneWire == NULL)
      return -1000;
  
    rom_address_t address;
    mOneWire->singleDeviceReadROM(address);
    mOneWire->convertTemperature(address, true, true); //Start temperature conversion, wait until ready
    return mOneWire->temperature(address);
  }
}