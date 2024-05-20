
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  ulong operator()(const Data& element) const noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data>{

private:

protected:

  using Container::size;

  ulong a = 3;
  ulong b = 5;
  
  ulong prime = 1069;
  ulong tableSize = 16;

  std::default_random_engine gen = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<ulong> genA = std::uniform_int_distribution<ulong>(1, prime);
  std::uniform_int_distribution<ulong> genB = std::uniform_int_distribution<ulong>(0, prime);

  //Constructor
  HashTable() {
    a = (genA(gen) * 2) + 1;
    b = std::pow(2, std::ceil(log2(genB(gen))));
  }

  //Copy constructor
  HashTable(const HashTable& right);

  //Move constructor
  HashTable(HashTable&& right) noexcept;

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator=(const HashTable& right); // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&& right) noexcept; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable& right) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool inline operator!=(HashTable&& right) const noexcept {
    return !(operator==(right));
  } // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions
  ulong HashKey(ulong key) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif