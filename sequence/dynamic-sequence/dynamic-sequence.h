#ifndef DYNAMIC_SEQUENCE_H
#define DYNAMIC_SEQUENCE_H

#include <iostream>
#include <vector>

#include "../sequence.h"
template<class Key>
class Sequence;
template<class Key>
class DynamicSequence : public Sequence<Key> {
 public:
  DynamicSequence<Key>(int blockSize, DispersionFunction<Key>& dispersionFunction) : Sequence<Key>(dispersionFunction) {
    this->blockSize_ = blockSize;
  }
  bool search(const Key& key) const override {
    // Check if key is in the block
    std::cout << "List size: " << keys_.size() << std::endl;
    for (int i = 0; i < keys_.size(); i++) {
      if (keys_[i] == key) {
        return true;
      }
    }
    return false;
  }

  bool insert(const Key& key) override {
    keys_.push_back(key);
    return true;
  }
  
 private:
  std::vector<Key> keys_;
  
};

#endif