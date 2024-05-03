
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  // type Insert(argument) specifiers; // Move of the value
  // type Remove(argument) specifiers;

  // type InsertAll(argument) specifiers; // Copy of the value; From TraversableContainer; True if all are inserted
  // type InsertAll(argument) specifiers; // Move of the value; From MappableContainer; True if all are inserted
  // type RemoveAll(argument) specifiers; // From TraversableContainer; True if all are removed

  // type InsertSome(argument) specifiers; // Copy of the value; From TraversableContainer; True if some is inserted
  // type InsertSome(argument) specifiers; // Move of the value; From MappableContainer; True if some is inserted
  // type RemoveSome(argument) specifiers; // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
