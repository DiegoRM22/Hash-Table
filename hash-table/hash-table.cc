
#include "hash-table.h"

/**
 * @brief Constructor for the closed hash table
 */
template<class Key, class Container>
HashTable<Key, Container>::HashTable(const int tableSize, DispersionFunction<Key>& dispersionFunction,
                                      ExplorationFunction<Key>& explorationFunction, int blockSize) {
  tableSize_ = tableSize;
  table_ = new Container[tableSize];
  for (int i = 0; i < tableSize; i++) {
    table_[i] = new Container(explorationFunction, dispersionFunction, blockSize);
  }
}

/**
 * @brief Constructor for the open hash table
 */
template<class Key, class Container>
HashTable<Key, Container>::HashTable(const int tableSize, DispersionFunction<Key>& dispersionFunction) {
  tableSize_ = tableSize;
  table_ = new Container[tableSize];
  for (int i = 0; i < tableSize; i++) {
    table_[i] = new Container();
  }
}