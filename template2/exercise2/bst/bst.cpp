#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const MappableContainer<Data>& right) {
  right.Map(
    [this](const Data& value){
      Insert(value);
    }
  );
}

template <typename Data>
BST<Data>::BST(MutableMappableContainer<Data>&& right) noexcept {
  right.Map(
    [this](const Data& value){
      Insert(std::move(value));
    }
  );
}

template<typename Data>
BST<Data>::BST(const BST<Data>& right): BinaryTreeLnk<Data>::BinaryTreeLnk(right) {;}

template<typename Data>
BST<Data>::BST(BST<Data>&& right) noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(right)) {;}

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& right){
  BinaryTreeLnk<Data>::operator=(right);
  return *this;
}
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& right)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(right));
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST &right) const noexcept {
  if (size == right.Size()) {
    BTInOrderIterator<Data> IterThis(*this);
    BTInOrderIterator<Data> IterORight(right);
    for (; !IterThis.Terminated(); ++IterThis, ++IterORight) {
      if((*IterThis) != (*IterORight)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <typename Data>
const Data &BST<Data>::Min() const {
  if (root != nullptr) {
      return FindPointerToMin(root)->element;
  } else {
      throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
Data BST<Data>::MinNRemove() {
  if (root != nullptr) {
      return DataNDelete(DetachMin(root));
  }
  else throw std::length_error("Error: BST isEmpty.");
}

template <typename Data>
void BST<Data>::RemoveMin() {
  if (root != nullptr) {
      delete DetachMin(root);
  } else {
      throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
const Data &BST<Data>::Max() const {
    if (root != nullptr) {
    return FindPointerToMax(root)->element;
  } else {
    throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
Data BST<Data>::MaxNRemove() {
  if (root != nullptr) {
    return DataNDelete(DetachMax(root));
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}

template<typename Data>
void BST<Data>::RemoveMax() {
  if (root != nullptr) {
    delete DetachMax(root);
  } else {
    throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
const Data &BST<Data>::Predecessor(const Data &find) const {
  NodeLnk* const* ptr =& FindPointerToPredecessor(root, find);
  if (ptr != nullptr) {
      return (*ptr)->element;
  } else {
      throw std::length_error("Error: Predecessor not found");
  }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data &find) {
  NodeLnk** ptr =&FindPointerToPredecessor(root, find);
  if (ptr != nullptr) {
    return DataNDelete(Detach(*ptr));
  } else {
    throw std::length_error("Error: Predecessor not found");
  }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data &find) {
  NodeLnk** puntatore=&FindPointerToPredecessor(root,find);
  if (puntatore != nullptr) {
      delete Detach(*puntatore);
  } else {
      throw std::length_error("Error: Predecessor not found");
  }
}

template <typename Data>
const Data &BST<Data>::Successor(const Data &find) const {
  NodeLnk* const* ptr =& FindPointerToSuccessor(root, find);
  if(ptr !=nullptr){
      return (*ptr)->element;
  }
  else{
      throw std::length_error("Error: Successor not found");
  }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data &find) {
  NodeLnk** ptr =& FindPointerToSuccessor(root, find);
  if (ptr != nullptr) {
      return DataNDelete(Detach(*ptr));
  } else {
      throw std::length_error("Error: Successor not found");
  }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data &find) {
  NodeLnk **ptr =& FindPointerToSuccessor(root, find);
  if (ptr != nullptr) {
      delete Detach(*ptr);
  } else {
      throw std::length_error("Error: Successor not found");
  }
}

template <typename Data>
bool BST<Data>::Insert(const Data &value) {
  NodeLnk * & ptr = FindPointerTo(root, value); 
  if(ptr == nullptr){
    ptr = new NodeLnk(value);
    size++;
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Insert(Data &&value){
    NodeLnk * & ptr = FindPointerTo(root, value); 
    if(ptr == nullptr){
    ptr = new NodeLnk(std::move(value));
    size++;
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Remove(const Data &value){
  NodeLnk * & ptr = FindPointerTo(root, value);
  if(ptr != nullptr){
    delete Detach(ptr);
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Exists(const Data &value) const noexcept {
  return (FindPointerTo(root,value) !=nullptr);
}

template <typename Data>
void BST<Data>::Clear() noexcept {
  BinaryTreeLnk<Data>::Clear();
}

template <typename Data>
inline Data BST<Data>::DataNDelete(NodeLnk *node) {
  Data value;
  std::swap(value, node->element);
  delete node;
  return value;
}

template <typename Data>
typename lasd::BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(NodeLnk *&node) noexcept {
  if (node != nullptr) {
    if (node->LChild == nullptr) {
      return Skip2Right(node);
    }
    else if (node->RChild == nullptr) {
      return Skip2Left(node);
    }
    else {
      NodeLnk *max = DetachMax(node->LChild);
      std::swap(node->element, max->element);
      return max;
    }
  }
  return nullptr;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(typename BST<Data>::NodeLnk*& node)noexcept{
  return Skip2Left(FindPointerToMax(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(typename BST<Data>::NodeLnk*& node) noexcept{
  NodeLnk* new_LChild = nullptr;
  if (node != nullptr) {
    std::swap(new_LChild, node->LChild);
    std::swap(new_LChild, node);
    size--;
  }
  return new_LChild;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(typename BST<Data>::NodeLnk*& node)noexcept{
  return Skip2Right(FindPointerToMin(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(typename BST<Data>::NodeLnk*& node) noexcept{
  NodeLnk *new_RChild = nullptr;
  if (node != nullptr) {
    std::swap(new_RChild, node->RChild);
    std::swap(new_RChild, node);
    size--;
  }
  return new_RChild;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk*& Nodo) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(Nodo));
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk*& Nodo) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(Nodo));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk* const& node)const noexcept{
  NodeLnk* const* punt=&node;
  NodeLnk* corrente=node;
  if(corrente!=nullptr){
    while(corrente->LChild!=nullptr){
      punt=&corrente->LChild;
      corrente=corrente->LChild;
    }
  }
  return *punt;
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk* const& Nodo)const noexcept{
  NodeLnk* const* puntatore=&Nodo;
  NodeLnk* corrente=Nodo;
  if(corrente!=nullptr){
    while(corrente->RChild!=nullptr){
      puntatore=&corrente->RChild;
      corrente=corrente->RChild;
    }
  }
  return *puntatore;
}



template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& Nodo, Data find) const noexcept{
  NodeLnk *const *puntatore = &Nodo;
  NodeLnk *corrente = Nodo;

  while (corrente != nullptr) {
    if (find > corrente->element) {
      puntatore = &corrente->RChild;
      corrente = corrente->RChild;
    } else if (find < corrente->element) {
      puntatore = &corrente->LChild;
      corrente = corrente->LChild;
    } else {
      break;
    }
  }
  return *puntatore;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& Nodo, Data find) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(Nodo,find));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& Nodo, Data find) const noexcept{
  NodeLnk *const *predecessore = nullptr;
  NodeLnk *const *corrente = &Nodo;

  while ((*corrente) != nullptr && (*corrente)->element != find) {
    if ((*corrente)->element > find) {
      corrente = &(*corrente)->LChild;
    } else if ((*corrente)->element < find) {
      predecessore = corrente;
      corrente = &(*corrente)->RChild;
    }
  }
  if ((*corrente) != nullptr && (*corrente)->LChild != nullptr) {
    predecessore = &FindPointerToMax((*corrente)->LChild);
  }

  return *predecessore;
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, Data find) const noexcept{
  typename BST<Data>::NodeLnk *const *successor = nullptr;
  typename BST<Data>::NodeLnk *const *current = &node;

  while ((*current) != nullptr && (*current)->element != find) {
    if ((*current)->element < find) current = &(*current)->RChild;
    else if ((*current)->element > find) {
      successor = current;
      current = &(*current)->LChild;
    }
  }
  if ((*current) != nullptr && (*current)->RChild != nullptr) successor = &FindPointerToMin((*current)->RChild);

  return *successor;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& Nodo, Data find) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(Nodo,find));
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& Nodo, Data find) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(Nodo,find));
}

/* ************************************************************************** */

}
