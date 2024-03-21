#ifndef NIF_H
#define NIF_H

#include <iostream>

class NIF {
 public:
  NIF(const std::string& nif) : nif_(nif) {
    nif_ = nif;
    int asciiValue = nif_[nif_.size() - 1];
    value_ = std::stol(nif.substr(0, nif.size() - 1) + std::to_string(asciiValue));
  }
  long getValue() const { return value_; }
  std::string getOriginal() const { return nif_; }
  bool operator==(const NIF& nif) const { return value_ == nif.value_; }
  bool operator!=(const NIF& nif) const { return value_ != nif.value_; }
  bool operator<(const NIF& nif) const { return value_ < nif.value_; }
  bool operator>(const NIF& nif) const { return value_ > nif.value_; }
 private:
  std::string nif_;
  long value_;
};

#endif