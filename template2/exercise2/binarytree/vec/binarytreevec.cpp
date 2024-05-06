#include "binarytreevec.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt) {
    this->bt = bt;
    this->index = i;
    bt->Elements[i] = dat;  
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt) {
    std::swap(this->bt, bt);
    std::swap(this->index, i);
    std::swap(bt->Elements[i], dat);  
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
{
    if(index*2+1 < bt->size) {
        return true;
    }
    return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    if(index*2+2 < bt->size) {
            return true;
    }
    return false;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return (bt->Nodes[index*2+1]);
    }
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return (bt->Nodes[index*2+2]);
    }
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) {
        return (bt->Nodes[index*2+1]);
    }
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) {
        return (bt->Nodes[index*2+2]);
    }
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& right) {
    this->Resize(right.Size());
    Nodes = new NodeVec[right.Size()];
    int i = 0;
    right.Map(
        [this, &i](const Data& dat){
            this->Nodes[i].index = i;
            Elements[i] = dat;
            this->Nodes[i].bt = this;
            i++;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> &&right) noexcept {
    this->Resize(right.Size());
    Nodes = new NodeVec[right.Size()];
    int i = 0;
    right.Map(
        [this, &i](Data& dat){
            this->Nodes[i].index = i;
            Elements[i] = std::move(dat);
            this->Nodes[i].bt = this;
            i++;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &right) {
    this->Resize(right.Size());
    Nodes = new NodeVec[right.Size()];
    std::copy(right.Elements, right.Elements + size, Elements);
    std::copy(right.Nodes, right.Nodes + size, Nodes);
    for(int i = 0; i < right.Size(); i++) {
        Nodes[i].bt = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&right) noexcept {
    std::swap(this->size, right.size);
    std::swap(Elements, right.Elements);
    std::swap(Nodes, right.Nodes);
    for(int i = 0; i < size; i++) {
        Nodes[i].bt = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& right) {
    this->Clear();
    this->Resize(right.Size());
    Nodes = new NodeVec[right.Size()];
    std::copy(right.Elements, right.Elements + size, Elements);
    std::copy(right.Nodes, right.Nodes + size, Nodes);
    for(int i = 0; i < right.Size(); i++) {
        Nodes[i].bt = this;
    }
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec &&right) noexcept {
    std::swap(this->size, right.size);
    std::swap(Elements, right.Elements);
    std::swap(Nodes, right.Nodes);
    for(int i = 0; i < size; i++) {
        Nodes[i].bt = this;
    }
    for(int i = 0; i < right.size; i++) {
        right.Nodes[i].bt = &right;
    }
    return *this;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(!this->Empty()) {
        return Nodes[0];
    }
    else {
        throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if(!this->Empty()) {
        return Nodes[0];
    }
    else {
        throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
    }
}

/* ************************************************************************** */

}
