
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
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {  

private:

  // ...

protected:

  using Container::size; 

public:

  struct Node {

  protected:

    // Comparison operators
    bool operator==(const Node& right) const noexcept {
      return (Element() == right.Element());
    }; // Comparison of abstract types is possible, but should not be visible.
    
    bool operator!=(const Node& right) const noexcept {
      return !(operator==(right));
    }; // Comparison of abstract types is possible, but should not be visible.

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

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

   using typename TraversableContainer<Data>::TraverseFun;

  virtual void Traverse(TraverseFun func) const override;  // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  virtual void PreOrderTraverse(TraverseFun func) const override;  // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  
  virtual void PostOrderTraverse(TraverseFun func) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  virtual void InOrderTraverse(TraverseFun func) const override; // Override InOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  virtual void BreadthTraverse(TraverseFun func) const override; // Override BreadthTraversableContainer member

protected:
 // Auxiliary member function (for PreOrderMappableContainer)

  void RecursivePreOrderTraverse(const Node *node, TraverseFun func) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for PostOrderMappableContainer)

  void RecursivePostOrderTraverse(const Node *node, TraverseFun func) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for InOrderMappableContainer)

  void RecursiveInOrderTraverse(const Node *node, TraverseFun func) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for BreadthMappableContainer)

  void NotRecursiveBreadthTraverse(const Node *node, TraverseFun func) const; // Accessory function executing from one node of the tree

};


/* ************************************************************************** */

template <typename Data>
  class MutableBinaryTree : virtual public ClearableContainer,
                            virtual public BinaryTree<Data>,
                            virtual public PreOrderMappableContainer<Data>,
                            virtual public PostOrderMappableContainer<Data>,
                            virtual public InOrderMappableContainer<Data>,
                            virtual public BreadthMappableContainer<Data> {


private:

  // ...

protected:

  // ...

public:

  struct MutableNode : public virtual BinaryTree<Data>::Node{

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode& operator=(const MutableNode& right) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    MutableNode& operator=(MutableNode&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)



    virtual const MutableNode& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual const MutableNode& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree<Data>& operator=(const MutableBinaryTree& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableBinaryTree<Data>& operator=(MutableBinaryTree&& right) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Specific member functions
  using BinaryTree<Data>::Root;
  virtual  MutableNode& Root()  = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

   using typename MappableContainer<Data>::MapFun;

  virtual void inline Map(MapFun func) override {
    PreOrderMap(func);
  }; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline virtual void PreOrderMap(MapFun func) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline virtual void PostOrderMap(MapFun func) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  inline virtual void InOrderMap(MapFun func) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  inline virtual void BreadthMap(MapFun func) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary member function (for PreOrderMappableContainer)

  void RecursivePreOrderMap(MutableNode *node, MapFun func); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for PostOrderMappableContainer)

  void RecursivePostOrderMap(MutableNode *node, MapFun func); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for InOrderMappableContainer)

  void RecursiveInOrderMap(MutableNode *node, MapFun func); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for BreadthMappableContainer)

  void NotRecursiveBreadthMap(MutableNode *node, MapFun func); // Accessory function executing from one node of the tree

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
