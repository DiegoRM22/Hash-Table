
#ifndef DISPERSION_FUNCTION_H
#define DISPERSION_FUNCTION_H

#include <iostream>

#include "../hash-table/hash-table.h"

template<class Key>
class DispersionFunction {
 public:
  DispersionFunction() {}
  virtual unsigned operator()(const Key& key) const = 0;
 protected:
  int tableSize_;
};

#endif