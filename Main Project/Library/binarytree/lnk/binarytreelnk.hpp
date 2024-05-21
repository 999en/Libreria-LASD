
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data>,
                      virtual public ClearableContainer{

private:

  // ...

protected:

  using Container::size;

 public:

   using typename BinaryTree<Data>::Node;
   using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeLnk : virtual MutableBinaryTree<Data>::MutableNode {  // Must extend MutableNode

  friend class BinaryTreeLnk<Data>;

  private:

  protected:

  public:

    Data element {};
    NodeLnk* LChild = nullptr;
    NodeLnk* RChild = nullptr;


    /* ********************************************************************** */

    //Specific Constructor

    NodeLnk(const Data& right) : element(right) {};
    NodeLnk(Data&& right) noexcept : element(std::move(right)) {};

    /* ********************************************************************** */

    //Copy Constructor
    NodeLnk(const NodeLnk& right);

    //Move Constructor
    NodeLnk(NodeLnk&& right) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~NodeLnk();

    /* ********************************************************************** */

    //Copy Assignament
    NodeLnk& operator=(const NodeLnk& right);

    //Move Assignament
    NodeLnk& operator=(NodeLnk&& right) noexcept;

    /* ********************************************************************** */

    // Specific member functions

    virtual bool inline IsLeaf() const noexcept override { return (!(HasLeftChild() || HasRightChild())); };

    virtual inline Data& Element() noexcept override {
      return element;
    };

    virtual const inline Data& Element() const noexcept override {
      return element;
    };

    virtual bool inline HasLeftChild() const noexcept override{
      return (LChild == nullptr ? false : true);
    };

    virtual bool inline HasRightChild() const noexcept override{
      return (RChild == nullptr ? false : true);
    };

    virtual inline MutableNode& LeftChild() override {
      if(IsLeaf()) {
        throw std::out_of_range("Left Child does not exists.");
      }
      return *LChild;
    }; 

    virtual const inline Node& LeftChild() const override {
      if(IsLeaf()) {
        throw std::out_of_range("Left Child does not exists.");
      }
      return *LChild;
    }; 

    virtual inline MutableNode& RightChild() override {
      if(IsLeaf()) {
        throw std::out_of_range("Right Child does not exists.");
      }
      return *RChild;
    };

    virtual const inline Node& RightChild() const override {
      if(IsLeaf()) {
        throw std::out_of_range("Right Child does not exists.");
      }
      return *RChild;
    };

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors

  BinaryTreeLnk(const TraversableContainer<Data>& right) ; // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data>&& right) noexcept ;   // A binary tree obtained from a MappableContainer
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
      delete root;
      root = nullptr;
      size = 0;
  }; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
