#ifndef CUADRATIC_EXPLORATION_H
#define CUADRATIC_EXPLORATION_H

#include <iostream>

#include "../exploration-function.h"

template<class Key>
class CuadraticExploration : public ExplorationFunction<Key> {
 public:
  CuadraticExploration();
  unsigned operator()(const Key& key, unsigned iteration) const override {
    return iteration * iteration;
  }
};

#endif