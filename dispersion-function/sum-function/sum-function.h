#ifndef SUM_FUNCTION_H
#define SUM_FUNCTION_H

#include <iostream>

#include "../dispersion-function.h"

template<class Key>
class DispersionFunction;

template<class Key>
class SumFunction : public DispersionFunction<Key> {
 public:
  SumFunction<Key>(int tableSize) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key) const override {
    unsigned sum = 0;
    Key auxKey = key;
    for (int i = 0; i < sizeof(key); i++) {
      sum += auxKey % 10;
      auxKey /= 10;
    }
    return sum % this->tableSize_;
  }
};

#endif