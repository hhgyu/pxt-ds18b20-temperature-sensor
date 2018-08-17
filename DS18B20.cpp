#include "pxt.h"

#include "OneWire.h"
#include <map>

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
  std::map<Pins, OneWire *> m;
  std::map<Pins, bool> mFinded;
  
  //%
  void init(Pins pin) {
    OneWire * oneWire = new OneWire((PinName) pin);
    auto it = m.find(pin);
    if (it != m.end()) {
      delete it->second;
      it->second = oneWire;
      mFinded[pin] = false;
    } else {
      m.insert(std::make_pair(pin, oneWire));
      mFinded.insert(std::make_pair(pin, false));
    }
	
    oneWire->init();

    if(oneWire->findAllDevicesOnBus() > 0) {
      mFinded[pin] = true;
    }
  }
  
  //%
  int get_temp(Pins pin) {
    auto it = m.find(pin);
    if (it != m.end()) {
      OneWire * oneWire = it->second;

      auto itFinded = mFinded.find(pin);
      if(itFinded != mFinded.end()) {
        if(!itFinded->second) {
          if(oneWire->findAllDevicesOnBus() > 0) {
            itFinded->second = true;
          }
        }

        if(itFinded->second) {
          rom_address_t & address = oneWire->getAddress(0);
          oneWire->convertTemperature(address, false, false); //Start temperature conversion, wait until ready
          float temp = oneWire->temperature(address);

          if(temp == -1000)
            return  -999999;
          return temp * 100;
        }
      }
    }

    return -999999;
  }

  //%
  void deinit(Pins pin) {
    auto it = m.find(pin);
    if (it != m.end()) {
      delete it->second;
      m.erase(it);
      mFinded.erase(pin);
    }
  }
}