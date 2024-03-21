#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>

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
                                      ExplorationFunction<Key>& explorationFunction, int blockSize)
    : dispersionFunction_(dispersionFunction), explorationFunction_(explorationFunction) {
    this->tableSize_ = tableSize;
    this->table_.resize(tableSize);
    isClosed_ = 1;
    for (int i = 0; i < tableSize; i++) {
        this->table_[i] = new StaticSequence<Key>(blockSize, explorationFunction, dispersionFunction);
    }
  }

  HashTable<Key, Container>(const int tableSize, DispersionFunction<Key>& dispersionFunction)
    : dispersionFunction_(dispersionFunction), explorationFunction_() {
    this->tableSize_ = tableSize;
    this->table_.resize(tableSize);
    for (int i = 0; i < tableSize; i++) {
        this->table_[i] = new DynamicSequence<Key>(dispersionFunction);
    }
  }

  void printTable() {
    for (int i = 0; i < tableSize_; i++) {
      std::cout << "Table[" << i << "]: ";
      table_[i]->print();
    }
  }

  bool insert(const Key& key) {
    int index = dispersionFunction_.operator()(key);
    int i = 0;
    // If the table is open
    if (isClosed_) {
      while (!table_[index]->insert(key)) {
        if (!table_[index]->isFull()) {
          return false;
        }
        std::cout << "Intentando insertar en bloque: " << index << std::endl;
        index = explorationFunction_.operator()(key, index);
      }
    }
    return true;
  }

  bool search(const Key& key) {
    int index = dispersionFunction_.operator()(key);
    std::cout << "Searching in block index " << index << std::endl;

    table_[index]->print();
    while (!table_[index]->search(key)) {
      if (!table_[index]->isFull()) {
        return false;
      }
      index = explorationFunction_.operator()(key, index);
      if (index == tableSize_) {
        index = 0;
      }
    }
    std::cout << "La clave " << key << " se encuentra en la tabla" << std::endl;
    return true;
  }

    

 protected:
  int tableSize_;
  std::vector<Container*> table_;
  DispersionFunction<Key>& dispersionFunction_ = new ModuleFunction<Key>();
  ExplorationFunction<Key>& explorationFunction_ = new LinealExploration<Key>();
  bool isClosed_ = 0;
};

#endif
