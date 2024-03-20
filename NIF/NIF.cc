
#include <iostream>

#include "NIF.h"

NIF::NIF(const std::string& nif) : nif_(nif) {
  nif_ = nif;
  int asciiValue = nif_[nif_.size() - 1];
  value_ = std::stol(nif.substr(0, nif.size() - 1) + std::to_string(asciiValue));
}