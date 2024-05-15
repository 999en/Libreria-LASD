
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>,
                      virtual protected Vector<Data> {

private:

  // ...

protected:

  // ...
  struct NodeVec : virtual MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  friend class BinaryTreeVec<Data>; 

  private:

  protected:

  public:

    BinaryTreeVec<Data>* bt = nullptr;
    int index;
delet
    // Specific constructor
    NodeVec() {
      bt = nullptr;
      index = 0;
    };
    NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt);
    NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt);

    // Destructor
    inline virtual ~NodeVec() = default;

    // Copy assignment
    inline NodeVec& operator=(const NodeVec& right) { 
      bt = right.bt;
      index = right.index;
      return *this;
    };

    // Move assignment
    inline NodeVec& operator=(NodeVec&& right) noexcept { 
      std::swap(bt, right.bt);
      std::swap(index = right.index); 
      return *this;
    };

    // Specific member functions
    inline virtual Data& Element() noexcept override { 
      return bt->elem[index];
    }
    inline virtual const Data& Element() const noexcept override { 
      return bt->elem[index]; 
    }

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual NodeVec& LeftChild() override;
    virtual const NodeVec& LeftChild() const override;

    virtual NodeVec& RightChild() override;
    virtual const NodeVec& RightChild() const override;
  };

  using Container::size;
  using Vector<Data>::elem;
  NodeVec* Nodes = nullptr;

public:

  
  using BinaryTree<Data>::Traverse;
  using BinaryTree<Data>::PreOrderTraverse;
  using BinaryTree<Data>::PostOrderTraverse;
  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data>& right) ; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(MappableContainer<Data>&& right) noexcept ;   // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>& right);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec(){
    delete[] Nodes;
    Nodes = nullptr;
  }

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec& right);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator==(right); 
  };
  inline bool operator!=(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator!=(right); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual const NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  virtual NodeVec& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual inline void Clear() override {
    Vector<Data>::Clear();
    delete[] Nodes;
    Nodes = nullptr;
  }; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

virtual void BreadthTraverse(TraverseFun) const override;// Override BreadthTraversableContainer member

  /* ************************************************************************ */
using typename MappableContainer<Data>::MapFun;

  // Specific member function (inherited from BreadthMappableContainer)
virtual void BreadthMap(MapFun func) override; // Override BreadthMappableContainer member

  void PreOrderTraverse(TraverseFun func) const override{
    BinaryTree<Data>::PreOrderTraverse(func);
  }

  void PreOrderMap(MapFun func) override{
    MutableBinaryTree<Data>::PreOrderMap(func);
  }  

  void PostOrderTraverse(TraverseFun func) const override{
    BinaryTree<Data>::PostOrderTraverse(func);
  }

  void PostOrderMap(MapFun func) override{
    MutableBinaryTree<Data>::PostOrderMap(func);
  }

  void Traverse(TraverseFun func) const override{
    BinaryTree<Data>::Traverse(func); 
  }

  void Map(MapFun func) override{
    MutableBinaryTree<Data>::Map(func); 
  }

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
