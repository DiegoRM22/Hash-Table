#ifndef NIF_H
#define NIF_H

#include <iostream>

class NIF {
 public:
  NIF(const std::string& nif);
  long getValue() const { return value_; }
  std::string getOriginal() const { return nif_; }
 private:
  std::string nif_;
  long value_;
};

#endif