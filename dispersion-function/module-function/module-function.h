#ifndef MODULE_FUNCTION_H
#define MODULE_FUNCTION_H

#include <iostream>

#include "../dispersion-function.h"

template<class Key>
class ModuleFunction : public DispersionFunction<Key> {
 public:
  ModuleFunction<Key>(int tableSize) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key) const override {
    return key % this->tableSize_;
  }
};

#endif