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
    return key % this->tableSize_;
  }
};

#endif