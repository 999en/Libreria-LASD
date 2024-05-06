
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data>{

private:

  // ...

protected:

  using Container::size;

  struct NodeLnk : virtual MutableBinaryTree<Data>::MutableNode {  // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    // ...

  };

public:


  // Default constructor
  BinaryTreeLnk() = default;

  // BinaryTreeLnk() specifiers;

  /* ************************************************************************ */

  // Specific constructors
BinaryTreeLnk(const TraversableContainer<Data>& right); // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(const MappableContainer<Data>& right); // A binary tree obtained from a MappableContainer
  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk& right);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk() {
    delete root;
  }

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator=(const BinaryTreeLnk& right);

  // Move assignment
  BinaryTreeLnk<Data>& operator=(BinaryTreeLnk&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeLnk& right) const noexcept { 
    return BinaryTree<Data>::operator==(right); 
  };
  inline bool operator!=(const BinaryTreeLnk& right) const noexcept { 
    return BinaryTree<Data>::operator!=(right); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  virtual inline const NodeLnk& Root() const override {
    if(this->Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)
  virtual inline NodeLnk& Root() override {
    if(this->Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual inline void Clear() override { 
    if (root != nullptr) { 
      delete root; 
      root=nullptr; 
    } 
    size = 0; 
  }; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
