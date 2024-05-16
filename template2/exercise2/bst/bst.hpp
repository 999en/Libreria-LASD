
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
  class BST : public virtual ClearableContainer,
              public virtual DictionaryContainer<Data>,
              public virtual BinaryTree<Data>,
              protected virtual BinaryTreeLnk<Data>   {


private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;

  using Container::size;
  using BinaryTreeLnk<Data>::root;

  // ...

public:


  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data>& right);// A bst obtained from a TraversableContainer
  BST(MappableContainer<Data>&& right) noexcept; // A bst obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST& right);

  // Move constructor
  BST(BST&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator=(const BST& right);

  // Move assignment
  BST<Data>& operator=(BST&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST& right) const noexcept;
  bool inline operator!=(const BST& right) const noexcept {
    return !(operator==(right));
  }
  /* ************************************************************************ */

  // Specific member functions

  const Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  const Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data& find) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data& find); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data& find); // (concrete function must throw std::length_error when not found)

  const Data& Successor(const Data& find) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data& find); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data& find); // (concrete function must throw std::length_error when not found)


  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  virtual const NodeLnk& Root() const noexcept override; // Override BinaryTree member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& value) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&& value) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data& value) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data& value) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() noexcept override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

  Data DataNDelete(NodeLnk* node);

  NodeLnk* Detach(NodeLnk*& node) noexcept;

  NodeLnk* DetachMin(NodeLnk *&) noexcept;
  NodeLnk* DetachMax(NodeLnk *&) noexcept;

  NodeLnk* Skip2Left(NodeLnk *&) noexcept;
  NodeLnk* Skip2Right(NodeLnk *&) noexcept;

  NodeLnk* const &FindPointerToMin(NodeLnk *const &nod) const noexcept;
  NodeLnk* const &FindPointerToMax(NodeLnk *const &nod) const noexcept;

  NodeLnk*& FindPointerToMin(NodeLnk *&nod) noexcept;
  NodeLnk*& FindPointerToMax(NodeLnk *&nod) noexcept;

  NodeLnk*const& FindPointerTo(NodeLnk *const &nod, Data dat) const noexcept;
  NodeLnk*& FindPointerTo(NodeLnk *&nod, Data dat) noexcept;

  NodeLnk* const& FindPointerToPredecessor(NodeLnk *const &nod, Data dat) const noexcept;
  NodeLnk* const& FindPointerToSuccessor(NodeLnk *const &nod, Data dat) const noexcept;

  NodeLnk*& FindPointerToPredecessor(NodeLnk *&nod, Data dat) noexcept;
  NodeLnk*& FindPointerToSuccessor(NodeLnk *&nod, Data dat) noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
