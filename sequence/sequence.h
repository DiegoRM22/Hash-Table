
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "../dispersion-function/dispersion-function.h"

#include <iostream>
template<class Key>
class Sequence {
 public:
  Sequence(DispersionFunction<Key>& dispersionFunction) : dispersionFunction_(dispersionFunction) {}
  virtual bool search(const Key& key) const = 0;
  virtual bool insert(const Key& key) = 0;
 protected:
  DispersionFunction<Key>& dispersionFunction_;
};

#endif