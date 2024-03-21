#ifndef CUADRATIC_EXPLORATION_H
#define CUADRATIC_EXPLORATION_H

#include <iostream>

#include "../exploration-function.h"

template<class Key>
class CuadraticExploration : public ExplorationFunction<Key> {
 public:
  CuadraticExploration(unsigned tableSize) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key, unsigned iteration) const override {
    if (iteration * iteration < this->tableSize_) {
      return iteration * iteration;
    } else {
      return (iteration * iteration) % this->tableSize_;
    }
  }
};

#endif