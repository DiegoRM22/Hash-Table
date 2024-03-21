#ifndef DOUBLE_DISPERSION_EXPLORATION_H
#define DOUBLE_DISPERSION_EXPLORATION_H

#include "../exploration-function.h"

template<class Key>
class DoubleDispersionExploration : public ExplorationFunction<Key> {
 public:
  DoubleDispersionExploration(const ExplorationFunction<Key>& auxiliarExplorationFunction, unsigned tableSize) : 
                              auxiliarExplorationFunction_(auxiliarExplorationFunction) {
    this->tableSize_ = tableSize;
  }
  unsigned operator()(const Key& key, unsigned iteration) const override {
    return iteration * auxiliarExplorationFunction_(key, iteration);
  }
 private:
  ExplorationFunction<Key> auxiliarExplorationFunction_;
};

#endif

