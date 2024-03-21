#ifndef REDISPERSION_EXPLORATION_H
#define REDISPERSION_EXPLORATION_H

#include "../exploration-function.h"
#include "../../dispersion-function/pseudo-random-function/pseudo-random-function.h"

template<class Key>
class RedispersionExploration : public ExplorationFunction<Key> {
 public:
  RedispersionExploration(const PseudoRandomFunction<Key>& pseudoRandomFunction, unsigned tableSize) : 
                              pseudoRandomFunction_(pseudoRandomFunction) {
    this->tableSize_ = tableSize;
                              }
  unsigned operator()(const Key& key, unsigned iteration) const override {
    return pseudoRandomFunction_(key);
  }
 private:
  PseudoRandomFunction<Key> pseudoRandomFunction_;
};

#endif
