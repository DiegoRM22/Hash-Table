
#ifndef STATIC_SEQUENCE_H
#define STATIC_SEQUENCE_H

#include "../sequence.h"
#include "../../exploration-function/exploration-function.h"

template<class Key>
class StaticSequence: public Sequence<Key> {
 public:
  StaticSequence<Key>(int blockSize, ExplorationFunction<Key>& explorationFunction,
  DispersionFunction<Key>& dispersionFunction);

  bool isFull() const;
  bool search(const Key& key) const;
  bool insert(const Key& key);

 private:
  ExplorationFunction<Key>& explorationFunction_;
  int blockSize_ = 1;
  Key block_[];
};

#endif