
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data>{

private:

  // ...

protected:

  using Container::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::tableSize;
  lasd::BST<Data>* table = nullptr;  

public:

  using DictionaryContainer<Data>::InsertAll;
  using DictionaryContainer<Data>::InsertSome;
  using DictionaryContainer<Data>::RemoveAll;
  using DictionaryContainer<Data>::RemoveSome;

  // Default constructor
  HashTableClsAdr() {
     table = new lasd::BST<Data>[tableSize] {};
  };

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong newSize); // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data>& right); // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const ulong newSize, const TraversableContainer<Data>& right); // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data>&& right) noexcept; // A hash table obtained from a MappableContainer
  HashTableClsAdr(const ulong newSize, MappableContainer<Data>&& right) noexcept; // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr<Data>& right);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr<Data>&& rigth) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() {
    delete[] table;
  };

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr& operator=(const HashTableClsAdr<Data>& right);

  // Move assignment
  HashTableClsAdr& operator=(HashTableClsAdr<Data>&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr<Data>& right) const noexcept;
  bool operator!=(const HashTableClsAdr<Data>& right) const noexcept {
    return !(operator==(right));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data& value) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&& value) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data& value) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  virtual void Resize(const ulong new_size) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif