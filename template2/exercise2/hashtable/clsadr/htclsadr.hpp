
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;

  // ...

public:

  // Default constructor
  // HashTableClsAdr() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;

  // Move constructor
  // HashTableClsAdr(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  // type Remove(argument) specifiers; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
