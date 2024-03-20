
#include <iostream>

#include "hash-table/hash-table.h"
#include "dispersion-function/dispersion-function.h"
#include "dispersion-function/sum-function/sum-function.h"
#include "dispersion-function/module-function/module-function.h"
#include "exploration-function/exploration-function.h"
#include "exploration-function/lineal-exploration/lineal-exploration.h"
#include "exploration-function/cuadratic-exploration/cuadratic-exploration.h"
#include "sequence/sequence.h"
#include "sequence/static-sequence/static-sequence.h"
#include "sequence/dynamic-sequence/dynamic-sequence.h"
#include "NIF/NIF.h"

template <class Key, class Container>
class HashTable;

int main() {
  NIF nif("12345A");
  long key = nif.getValue();
  unsigned iterator = 0;
  DispersionFunction<long> *dispersionFunction = new ModuleFunction<long>(key);
  ExplorationFunction<long> *explorationFunction = new LinealExploration<long>();
  HashTable<long> hashTable(10, *dispersionFunction, *explorationFunction, 3);


  return 0;
}