#ifndef EXPLORATION_FUNCTION_H
#define EXPLORATION_FUNCTION_H

#include <iostream>

template<class Key>
class ExplorationFunction {
 public:
  ExplorationFunction() {}
  virtual unsigned operator()(const Key& key, unsigned iteration) const = 0;
 protected: 
  unsigned tableSize_;
};

#endif