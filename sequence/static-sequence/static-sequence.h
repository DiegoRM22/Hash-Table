#ifndef STATIC_SEQUENCE_H
#define STATIC_SEQUENCE_H

#include "../sequence.h"
#include "../../exploration-function/exploration-function.h"

template<class Key>
class StaticSequence: public Sequence<Key> {
 public:
  StaticSequence<Key>(int blockSize, ExplorationFunction<Key>& explorationFunction,
  DispersionFunction<Key>& dispersionFunction) : Sequence<Key>(dispersionFunction),
                                                 blockSize_(blockSize),
                                                 explorationFunction_(explorationFunction),
                                                 block_(new Key[blockSize]) {
    for (int i = 0; i < blockSize; i++) {
      block_[i] = Key(); // Initialize with default constructor for type Key
    }
  }

  ~StaticSequence() {
    delete[] block_; // Free dynamically allocated memory
  }

  bool isFull() const {
    return block_[blockSize_ - 1].calculatesValue() != Key().calculatesValue();
  }

  bool search(const Key& key) const override {
    std::cout << "Searching for key: " << key << std::endl;
    for (int i = 0; i < blockSize_; i++) {
      if (block_[i] == key) {
        std::cout << "Found key: " << key << std::endl;
        return true;
      }
    }
    return false;
  }

  bool insert(const Key& key) override {
    if (isFull()) {
      return false;
    }
    for (int i = 0; i < blockSize_; i++) {
      if (block_[i] == Key()) {
        block_[i] = key;
        return true;
      }
    }
    return false;
  }  

  void print() {
    for (int i = 0; i < blockSize_; i++) {
      std::cout << block_[i] << " ";
    }
    std::cout << std::endl;
  }

 private:
  ExplorationFunction<Key>& explorationFunction_;
  int blockSize_;
  Key* block_; // Use a pointer for dynamically allocated memory
};

#endif
