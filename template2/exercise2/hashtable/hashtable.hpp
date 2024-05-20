
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

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;

  // ...

public:

  // Destructor
  // ~HashTable() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
