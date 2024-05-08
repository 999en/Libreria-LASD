#include "binarytreevec.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt) : bt(bt), index(i) {
    bt->Elements[i] = dat;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt) : bt(bt), index(i) {
    std::swap(bt->Elements[i], dat);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return index * 2 + 1 < bt->size;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return index * 2 + 2 < bt->size;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (HasLeftChild()) {
        return bt->Nodes[index * 2 + 1];
    }
    else {
        throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
    }
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (HasRightChild()) {
        return bt->Nodes[index * 2 + 2];
    }
    else {
        throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if (HasLeftChild()) {
        return bt->Nodes[index * 2 + 1];
    }
    else {
        throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if (HasRightChild()) {
        return bt->Nodes[index * 2 + 2];
    }
    else {
        throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
    }
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(TraversableContainer<Data> &&right) noexcept {
    Resize(right.Size());
    Nodes = new NodeVec[size];
    int i = 0;
    right.Traverse([this, &i](const Data& dat) {
        Nodes[i] = NodeVec(dat, i, this);
        i++;
    });
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& right) {
    Resize(right.Size());
    Nodes = new NodeVec[size];
    int i = 0;
    right.Map([this, &i](Data& dat) {
        Nodes[i] = NodeVec(std::move(dat), i, this);
        i++;
    });
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& right) {
    Resize(right.size);
    Nodes = new NodeVec[size];
    std::copy(right.Elements, right.Elements + size, Elements);
    std::copy(right.Nodes, right.Nodes + size, Nodes);
    for (int i = 0; i < size; i++) {
        Nodes[i].bt = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& right) noexcept{
    std::swap(size, right.size);
    std::swap(Elements, right.Elements);
    std::swap(Nodes, right.Nodes);
    for (int i = 0; i < size; i++) {
        Nodes[i].bt = this;
    }
    for (int i = 0; i < right.size; i++) {
        right.Nodes[i].bt = &right;
    }
}


template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& right) {
    if (this != &right) {
        Clear();
        Resize(right.size);
        Nodes = new NodeVec[size];
        std::copy(right.Elements, right.Elements + size, Elements);
        std::copy(right.Nodes, right.Nodes + size, Nodes);
        for (int i = 0; i < size; i++) {
            Nodes[i].bt = this;
        }
    }
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& right) noexcept {
    if (this != &right) {
        Clear();
        std::swap(size, right.size);
        std::swap(Elements, right.Elements);
        std::swap(Nodes, right.Nodes);
        for (int i = 0; i < size; i++) {
            Nodes[i].bt = this;
        }
        for (int i = 0; i < right.size; i++) {
            right.Nodes[i].bt = &right;
        }
    }
    return *this;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if (!Container::Empty()) {
        return Nodes[0];
    } else {
        throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
    }
}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if (!Container::Empty()) {
        return Nodes[0];
    }
    else {
        throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
    }
}

/* ************************************************************************** */

}
