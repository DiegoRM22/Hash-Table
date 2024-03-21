#ifndef PSEUDO_RANDOM_FUNCTION_H
#define PSEUDO_RANDOM_FUNCTION_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>


#include "../dispersion-function.h"

template<class Key>
class PseudoRandomFunction : public DispersionFunction<Key> {
 public:
  PseudoRandomFunction<Key>(int tableSize) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key) const override {
    // Initialize the seed
    int value = key;
    return rand() % this->tableSize_;
  }
};

#endif