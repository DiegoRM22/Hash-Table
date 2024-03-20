#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>

#include "../sequence/sequence.h"
#include "../sequence/static-sequence/static-sequence.h"
#include "../sequence/dynamic-sequence/dynamic-sequence.h"
#include "../dispersion-function/dispersion-function.h"
#include "../dispersion-function/sum-function/sum-function.h"
#include "../dispersion-function/module-function/module-function.h"
#include "../dispersion-function/pseudo-random-function/pseudo-random-function.h"
#include "../exploration-function/exploration-function.h"
#include "../exploration-function/cuadratic-exploration/cuadratic-exploration.h"
#include "../exploration-function/lineal-exploration/lineal-exploration.h"
#include "../exploration-function/redispersion-exploration/redispersion-exploration.h"
#include "../exploration-function/double-dispersion-exploration/double-dispersion-exploration.h"

template<class Key>
class StaticSequence;


template<class Key, class Container = StaticSequence<Key>>
class HashTable {
 public:
  HashTable<Key, Container>(const int tableSize, DispersionFunction<Key>& dispersionFunction,
  ExplorationFunction<Key>& explorationFunction, int blockSize = 1);

  HashTable<Key, Container>(const int tableSize, DispersionFunction<Key>& dispersionFunction);

 protected:
  int tableSize_;
  Container* table_[];
};

#endif
