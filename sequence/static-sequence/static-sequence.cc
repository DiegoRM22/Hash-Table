
#include "static-sequence.h"


/**
 * @brief Constructor
*/
template<class Key>
StaticSequence<Key>::StaticSequence(int blockSize, ExplorationFunction<Key>& explorationFunction,
  DispersionFunction<Key>& dispersionFunction) : Sequence<Key>(dispersionFunction),
                                                 blockSize_(blockSize),
                                                 explorationFunction_(explorationFunction),
                                                 block_(new Key[blockSize]) {
  for (int i = 0; i < blockSize; i++) {
    block_[i] = NULL;
  }
}


/**
 * @brief Check if the sequence is full
*/
template<class Key>
bool StaticSequence<Key>::isFull() const {
  return block_[blockSize_ - 1] != NULL;
}

/**
 * @brief Search for a key in the sequence
*/
template<class Key>
bool StaticSequence<Key>::search(const Key& key) const {
  for (int i = 0; i < blockSize_; i++) {
    if (block_[i] == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Insert a key in the sequence
*/
template<class Key>
bool StaticSequence<Key>::insert(const Key& key) {
  if (isFull()) {
    return false;
  }
  for (int i = 0; i < blockSize_; i++) {
    if (block_[i] == NULL) {
      block_[i] = key;
      return true;
    }
  }
  return false;
}

