#ifndef PSEUDO_RANDOM_FUNCTION_H
#define PSEUDO_RANDOM_FUNCTION_H

#include <iostream>
#include <stdlib.h>

#include "../dispersion-function.h"

template<class Key>
class PseudoRandomFunction : public DispersionFunction<Key> {
 public:
  PseudoRandomFunction<Key>(int tableSize) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key) const override {
    int value = key;
    srand(value);
    return rand() % this->tableSize_;
  }
};

#endif