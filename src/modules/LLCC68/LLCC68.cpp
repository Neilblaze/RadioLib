#include "LLCC68.h"
#if !defined(RADIOLIB_EXCLUDE_SX126X)

LLCC68::LLCC68(Module* mod) : SX1262(mod) {

}

int16_t LLCC68::setBandwidth(float bw) {
  RADIOLIB_CHECK_RANGE(bw, 100.0, 510.0, ERR_INVALID_BANDWIDTH);
  return(SX1262::setBandwidth(bw));
}

int16_t LLCC68::setSpreadingFactor(uint8_t sf) {
  switch(SX126x::_bw) {
    case SX126X_LORA_BW_125_0:
      RADIOLIB_CHECK_RANGE(sf, 5, 9, ERR_INVALID_SPREADING_FACTOR);
      break;
    case SX126X_LORA_BW_250_0:
      RADIOLIB_CHECK_RANGE(sf, 5, 10, ERR_INVALID_SPREADING_FACTOR);
      break;
    case SX126X_LORA_BW_500_0:
      RADIOLIB_CHECK_RANGE(sf, 5, 11, ERR_INVALID_SPREADING_FACTOR);
      break;
    default:
      return(ERR_INVALID_SPREADING_FACTOR);
  }

  return(SX1262::setSpreadingFactor(sf));
}

#endif
