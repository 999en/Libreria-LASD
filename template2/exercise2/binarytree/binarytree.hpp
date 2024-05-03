
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderMappableContainer<Data>,
                   virtual public PostOrderMappableContainer<Data>,
                   virtual public InOrderMappableContainer<Data>,
                   virtual public BreadthMappableContainer<Data> {  

private:

  // ...

protected:

  using Container::size; 

public:

  struct Node {

  protected:

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but is not visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but is not visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node& right) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept{
      return ((!HasLeftChild()) && (!HasRightChild()));
    }; // (concrete function should not throw exceptions)

    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual const Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

    virtual const Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  
  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree<Data>& operator=(const BinaryTree& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree<Data>& operator=(BinaryTree&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree& right) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree& right) const noexcept {
    return !(operator==(right));
  };  // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node& Root() const = 0; // (concrete function must throw std::length_error when empty)
              // TO DO MARY SOMMELLA
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // type InOrderTraverse(arguments) specifiers; // Override InOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree {
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode {
    // Must extend Node

    // friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~MutableNode() specifiers

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : public virtual ForwardIterator<Data>,
                           public virtual ResettableIterator<Data>{

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  const typename BinaryTree<Data>::Node* current=nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>& right); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator& right);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator& right);

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator& right) const noexcept;
  bool operator!=(const BTPreOrderIterator& right) const noexcept {
    return !(operator==(right));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator<Data>& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>,
                                  virtual public BTPreOrderIterator<Data> {

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  BTPreOrderMutableIterator(MutableBinaryTree<Data>& right) : BTPreOrderIterator<Data>(right) {;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& right) : BTPreOrderIterator<Data>(right) {;};

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& right) noexcept : BTPreOrderIterator<Data>(std::move(right)) {;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator& right);

  // Move assignment
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderMutableIterator& right) const noexcept { 
    return BTPreOrderIterator<Data>::operator==(right); 
  };
  inline bool operator!=(const BTPreOrderMutableIterator& right) const noexcept { 
    return BTPreOrderIterator<Data>::operator!=(right); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
  if(this->current!=nullptr) {
    return const_cast<Data&>((this->current)->Element());
  } else {
    throw std::out_of_range("Error: Out of range iterator"); 
  } 
}; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : public virtual ForwardIterator<Data>, 
                            public virtual ResettableIterator<Data>{

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  const typename BinaryTree<Data>::Node* current=nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

  const typename BinaryTree<Data>::Node* DeepestLeftLeaf(const typename BinaryTree<Data>::Node* actual);

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>& right); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator& right);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator<Data>& right);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator<Data>&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator& right) const noexcept;
  inline bool operator!=(const BTPostOrderIterator& right) const noexcept { 
    return !(operator==(right)); 
  }

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator<Data>& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>,
                                   virtual public BTPostOrderIterator<Data> {

private:

protected:

public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>& right) : BTPostOrderIterator<Data>(right) {;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator& right) : BTPostOrderIterator<Data>(right) {;};

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&& right) noexcept : BTPostOrderIterator<Data>(std::move(right)) {;};

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator& right);

  // Move assignment
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPostOrderMutableIterator& right) const noexcept { 
    return BTPostOrderIterator<Data>::operator==(right); 
  };
  inline bool operator!=(const BTPostOrderMutableIterator& right) const noexcept { 
    return !(operator==(right)); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current!=nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Out of range iterator"); 
    } 
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {

private:

protected:

  const typename BinaryTree<Data>::Node* current=nullptr;
  const typename BinaryTree<Data>::Node* root=nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

  const typename BinaryTree<Data>::Node* MostLeftNode(const typename BinaryTree<Data>::Node* );

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>& right); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator& right);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator& right);

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator& right) const noexcept;
  inline bool operator!=(const BTInOrderIterator& right) const noexcept { 
    return !(operator==(right)); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator<Data>& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTInOrderIterator<Data> {

private:

protected:

public:

  // Specific constructors
  BTInOrderMutableIterator(MutableBinaryTree<Data>& right) : BTInOrderIterator<Data>(right) {;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator& right) : BTInOrderIterator<Data>(right) {;};

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator&& right) noexcept : BTInOrderIterator<Data>(std::move(right)) {;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator& right);

  // Move assignment
  inline BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTInOrderMutableIterator& right) const noexcept { 
    return BTInOrderIterator<Data>::operator==(right); 
  };
  inline bool operator!=(const BTInOrderMutableIterator& right) const noexcept { 
    return !(operator==(right)); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current!=nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Out of range iterator"); 
    } 
  }; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */



template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>, 
                          virtual public ResettableIterator<Data> {

private:

protected:

  const typename BinaryTree<Data>::Node* current=nullptr;
  const typename BinaryTree<Data>::Node* root=nullptr;
  QueueVec<const typename BinaryTree<Data>::Node*> queue;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>& right); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator& right);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator& right);

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator& right) const noexcept;
  inline bool operator!=(const BTBreadthIterator& right) const noexcept { 
    return !(operator==(right)); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */


template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {

private:

protected:

public:

  // Specific constructors
  BTBreadthMutableIterator(MutableBinaryTree<Data>& right) : BTBreadthIterator<Data>(right) {;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator& right) : BTBreadthIterator<Data>(right) {;};

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator&& right) noexcept : BTBreadthIterator<Data>(std::move(right)) {;};

  /* ************************************************************************ */

  // Destructor
  ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator& right);

  // Move assignment
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTBreadthMutableIterator& right) const noexcept { 
    return BTBreadthIterator<Data>::operator==(right); 
  };
  inline bool operator!=(const BTBreadthMutableIterator& right) const noexcept { 
    return !(operator==(right)); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current!=nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Out of range iterator"); 
    } 
  }; 

};

/* ************************************************************************** */

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
