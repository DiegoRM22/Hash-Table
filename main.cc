
#include <iostream>
#include <cstdlib>
#include <ctime>

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
#include "network-card/network-card.h"

template <class Key, class Container>
class HashTable;

/**
 * @brief Get the Args object
 * 
 * @param argc 
 * @param argv 
 * @return std::string 
 */
std::string getArgs(int argc, char** argv) {
  std::string args;
  for (int i = 1; i < argc; i++) {
    args += argv[i];
    if (i < argc - 1) {
      args += " ";
    }
  }
  return args;
}

/**
 * @brief Set the Args object
*/
void setArgs(unsigned& tableSize, int& dispersionType, std::string& type, unsigned& blockSize, 
             int& explorationType, std::string arguments = "") {
  size_t i = 0;
  while (i < arguments.size()) {
    if (arguments[i] == '-') {
      switch(arguments[i + 1]) {
        case 't':
          tableSize = std::stoi(arguments.substr(i + 3));
          break;
        case 'd':
          dispersionType = std::stoi(arguments.substr(i + 3, 1));
          break;
        case 'e':
          explorationType = std::stoi(arguments.substr(i + 3, 1));
          break;
        case 'b':
          blockSize = std::stoi(arguments.substr(i + 3));
          break;
        case 'y':
          type = arguments.substr(i + 3, 4);
          break;
        default:
          break;
      }
    }
    i++;
  }
}


int main(int argc, char** argv) {
  srand(time(NULL));
  unsigned tableSize = 10;
  NIF nif("12345A");
  long key = nif.getValue();
  unsigned iterator = 0;
  DispersionFunction<NetworkCard> *dispersionFunction = new ModuleFunction<NetworkCard>(10);
  ExplorationFunction<NetworkCard> *explorationFunction = new LinealExploration<NetworkCard>(10);
  int explorationType = 0;
  int dispersionType = 0;
  unsigned blockSize = 3;
  std::string tableType = "open";
  setArgs(tableSize, dispersionType, tableType, blockSize, explorationType, getArgs(argc, argv));

  HashTable<NetworkCard> hashTable(tableSize, *dispersionFunction, *explorationFunction, blockSize);
  std::string input = "";
  while (input != "exit") {
    std::cout << "Enter a MAC address: ";
    std::cin >> input;
    NetworkCard networkCard(input);
    long key = networkCard.calculatesValue();
    std::cout << "La long key es: " << key << std::endl;
    hashTable.insert(networkCard);
    hashTable.printTable();
  }

  return 0;
}