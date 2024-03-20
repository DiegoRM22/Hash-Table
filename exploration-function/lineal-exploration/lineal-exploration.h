#ifndef LINEAL_EXPLORATION_H
#define LINEAL_EXPLORATION_H

#include <iostream>

#include "../exploration-function.h"

template<class Key>
class LinealExploration : public ExplorationFunction<Key> {
 public:
  LinealExploration() {}
  unsigned operator()(const Key& key, unsigned iteration) const override {
    return iteration;
  }
};

#endif