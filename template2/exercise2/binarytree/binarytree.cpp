#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool BinaryTree<Data>::operator==(const BinaryTree &right) const noexcept {
    if(size!=right.size) {
        return false;
    }
    BTPreOrderIterator i(*this);
    BTPreOrderIterator j(right);
    while(!(i.Terminated()) && !(j.Terminated())){
        if((*i)!=(*j)) {
            return false;
        }
        ++i; ++j;
    }
    return true;
}

template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun func, void *acc) const {
    if(!this->Empty()) {
        PreOrderMap( 
                [&func, &acc](const Data& dat) {
                    func(dat, acc);
                }
            );
    }
}



template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun func) const {
  if(!(this->Empty())) {
    RecursivePreOrderTraverse(&this->Root(), func);
  }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun func) const {
    if(!this->Empty()) {
        RecursivePostOrderTraverse(&this->Root(), func);
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun func) const {
    if(!this->Empty()) {
        RecursiveInOrderTraverse(&this->Root(), func);
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun func) const{
    if(!this->Empty()) {
        NotRecursiveBreadthTraverse(&this->Root(), func);
    }
}

template <typename Data>
void BinaryTree<Data>::RecursivePreOrderTraverse(const Node* node, TraverseFun func) const {
    func(node->Element());    
    if(node->HasLeftChild()) {
        RecursivePreOrderTraverse(&node->LeftChild(), func);
    } 
    if(node->HasRightChild()) {
        RecursivePreOrderTraverse(&node->RightChild(), func);
    }      
}

template <typename Data>
void BinaryTree<Data>::RecursivePostOrderTraverse(const Node* node, TraverseFun func) const {
    if(node->HasLeftChild()) {
        RecursivePostOrderTraverse(&node->LeftChild(), func);
    }
    if(node->HasRightChild()) {
        RecursivePostOrderTraverse(&node->RightChild(), func);
    }
    func(node->Element());
}

template <typename Data>
void BinaryTree<Data>::RecursiveInOrderTraverse(const Node* node, TraverseFun func) const {
    if(node->HasLeftChild()) {
        RecursiveInOrderTraverse(&node->LeftChild(), func);
    }
    func(node->Element());
    if(node->HasRightChild()) {
        RecursiveInOrderTraverse(&node->RightChild(), func);
    }
}

template <typename Data>
void BinaryTree<Data>::NotRecursiveBreadthTraverse(const Node* node, TraverseFun func) const {
    lasd::QueueVec<const BinaryTree<Data>::Node *> queue;
    if(node!=nullptr) {
        queue.Enqueue(node);
    }

    while (!queue.Empty()) {
        const BinaryTree<Data>::Node *currentNode = queue.HeadNDequeue();
        func(currentNode->Element());

        if(currentNode->HasLeftChild()) {
            queue.Enqueue(&currentNode->LeftChild());
        }

        if(currentNode->HasRightChild()) {
            queue.Enqueue(&currentNode->RightChild());
        }
    }
}


template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun func) {
    if(!(this->Empty())) {
        RecursivePreOrderMap(&this->Root(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderTraverse(TraverseFun func){
    if(!(this->Empty())) {
        RecursivePostOrderTraverse(&this->Root(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderTraverse(TraverseFun func){
    if(!(this->Empty())) {
       RecursiveInOrderTraverse(&this->Root(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthTraverse(TraverseFun func){
    if(!(this->Empty())) {
        NotRecursiveBreadthTraverse(&this->Root(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePreOrderTraverse(MutableNode* node, TraverseFun func) {
    func(node->Element());
    if(node->HasLeftChild()) {
        RecursivePreOrderTraverse(&node->LeftChild(), func);
    }
    if(node->HasRightChild()) {
        RecursivePreOrderTraverse(&node->RightChild(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePostOrderTraverse(MutableNode* node, TraverseFun func){
    if(node->HasLeftChild()) {
        RecursivePostOrderTraverse(&node->LeftChild(), func);
    }
    if(node->HasRightChild()) {
        RecursivePostOrderTraverse(&node->RightChild(), func);
    }
    func(node->Element());
}

template <typename Data>
void MutableBinaryTree<Data>::RecursiveInOrderMap(MutableNode* node, TraverseFun func){
    if(node->HasLeftChild()) {
        RecursiveInOrderTraverse(&node->LeftChild(), func);
    }
    func(node->Element());
    if(node->HasRightChild()) {
        RecursiveInOrderTraverse(&node->RightChild(), func);
    }
}

template <typename Data>
void MutableBinaryTree<Data>::NotRecursiveBreadthTraverse(MutableNode* node, TraverseFun func){
    lasd::QueueVec<MutableBinaryTree<Data>::MutableNode *> queue;
    if(node!=nullptr) {
        queue.Enqueue(node);
    }

    while (!queue.Empty()) {
        MutableBinaryTree<Data>::MutableNode *currentNode = queue.HeadNDequeue();
        func(currentNode->Element());

        if(currentNode->HasLeftChild()) {
            queue.Enqueue(&currentNode->LeftChild());
        }

        if(currentNode->HasRightChild()) {
            queue.Enqueue(&currentNode->RightChild());
        }
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& right) {
    if(!right.Empty()) {
        root = &right.Root();
        current = root;
    }
}


template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator &right) : stack(right.stack) {
    root = right.root;
    current = right.current;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(root, right.root);
    std::swap(current, right.current); 
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& right) {
    root = right.root;
    stack = right.stack;
    current = right.current;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& right) noexcept {
    std::swap(root, right.root);
    std::swap(stack, right.stack); 
    std::swap(current, right.current);
    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator &right) const noexcept {
    return (current==right.current && stack==right.stack);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Iterator is terminated.");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(!Terminated()){
        if(current->HasLeftChild()){
            if(current->HasRightChild()) {
                stack.Push(&current->RightChild());
            }
            current=&(current->LeftChild());
        }else if(current->HasRightChild()) { 
            current=&(current->RightChild());
        } else if (!stack.Empty()) {
            current=stack.TopNPop();
        } else {
            current=nullptr;
        }
    } else {
        throw std::out_of_range("Out of range iterator");
    }
    return *this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    stack.Clear();
    current = root;
}

/* ************************************************************************** */

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& right){
    if(right.Empty()) {
        root = nullptr;
    } else {
        root = &right.Root();
    }
    current = DeepestLeftLeaf(root);
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& right) {
    stack = right.stack;
    root = right.root;
    current=right.current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(root, right.root); 
    std::swap(current, right.current);
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Iterator is terminated.");
    }
    else {
        return current->Element();
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
    if(!Terminated()){
        if(!(stack.Empty())){
            if (stack.Top()->HasRightChild() && !(&(stack.Top()->RightChild()) == current)) {
                current = &(stack.Top()->RightChild());
                current = DeepestLeftLeaf(current);
            } else {
                current = stack.TopNPop();
            }
        } else {
            current = nullptr;
        }
    }
    else {
        throw std::out_of_range("Iterator is terminated.");
    }

    return *this;
}

template <typename Data>
const typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::DeepestLeftLeaf(const typename BinaryTree<Data>::Node* actual){
    if(actual!=nullptr){
        while(actual->HasLeftChild()){
            stack.Push(actual);
            actual = &(actual->LeftChild());
        }
        if(actual->HasRightChild()){
            stack.Push(actual);
            actual = &(actual->RightChild());
            actual = DeepestLeftLeaf(actual);
        }
    }
    return actual;
}


template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stack.Clear();
    current = DeepestLeftLeaf(root);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& right) {
    root=right.root;
    stack=right.stack;
    current=right.current;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& right) noexcept {
    std::swap(root, right.root);
    std::swap(stack, right.stack); 
    std::swap(current, right.current);
    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator &right) const noexcept {
    return ((current == right.current) && (stack == right.stack));
}

/* ************************************************************************** */

template <typename Data>
const typename BinaryTree<Data>::Node *BTInOrderIterator<Data>::MostLeftNode(const typename BinaryTree<Data>::Node* actual) {
   while (actual != nullptr && (actual->HasLeftChild())) {
        stack.Push(actual);
        actual = &actual->LeftChild();
    }
    return actual;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &right) {
    if(right.Empty()) {
        root = nullptr;
    } else {
        root = &right.Root();
    }
    current = MostLeftNode(root);
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& right) {
    stack = right.stack;
    root = right.root;
    current=right.current;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(current, right.current);
    std::swap(root, right.root); 
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& right) {
    root = right.root;
    stack = right.stack;
    current = right.current;
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& right) noexcept {
    std::swap(root, right.root);
    std::swap(stack, right.stack);
    std::swap(current, right.current);
    return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator &right) const noexcept {
    return ((current == right.current) && (stack == right.stack));
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Iterator is terminated.");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(!Terminated()) {
        if((stack.Empty()) && !(current->HasRightChild())) {
            current=nullptr;
        }
        else { 
            if(current->HasRightChild()){
                current = MostLeftNode(&current->RightChild());
            } 
            else {
                current = stack.TopNPop();
            }
        }
    } else {
        throw std::out_of_range("Iterator is terminated.");
    }

    return *this;
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stack.Clear(); 
    current = MostLeftNode(root);
}

/* ************************************************************************** */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& right) {
    if(right.Empty()) {
        root = nullptr;
    } else {
        root = &right.Root();
    }
    current = root;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &right) {
    queue = right.queue;
    root = current = right.current;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& right) noexcept : queue(std::move(right.queue)) {
    std::swap(root, right.root);
    std::swap(current, right.current); 
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& right) {
    root = right.root;
    queue = right.queue;
    current = right.current;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& right) noexcept {
    std::swap(root, right.root);
    std::swap(queue, right.queue);
    std::swap(current, right.current);
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator &right) const noexcept {
    return (current == right.current && queue == right.queue);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if(Terminated()) {
        throw std::out_of_range("Iterator is terminated.");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(!Terminated()) {
        if (current != nullptr) {
            if (current->HasLeftChild()) queue.Enqueue(&(current->LeftChild())); 
            if (current->HasRightChild()) queue.Enqueue(&(current->RightChild()));
            
            if (!queue.Empty()) current = queue.HeadNDequeue();
            else current = nullptr;
        } 
    } else {
        throw std::out_of_range("Iterator is terminated.");
    }

    return *this;
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    queue.Clear();
    current = root;
}


/* ************************************************************************** */


template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator& right) {
    this->root=right.root;
    this->stack=right.stack;
    this->current=right.current;
    return *this;
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator&& right) noexcept {
    this->root = std::move(right.root);
    this->stack = std::move(right.stack);
    this->current = std::move(right.current); 
    return *this;
}


template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator& right) {
    this->root=right.root;
    this->stack=right.stack;
    this->current=right.current;
    return *this;
}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator&& right) noexcept {
    std::swap(this->root, right.root);
    std::swap(this->stack, right.stack);    
    std::swap(this->current, right.current);
    return *this;
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator& right) {
    this->root=right.root;
    this->stack=right.stack;
    this->current=right.current;
    return *this;
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator&& right) noexcept {
    std::swap(this->root, right.root);
    std::swap(this->stack, right.stack);
    std::swap(this->current, right.current);
    return *this;
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator& right) {
    this->root=right.root;
    this->queue=right.queue;
    this->current=right.current;
    return *this;
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator&& right) noexcept {
    std::swap(this->root, right.root);
    std::swap(this->queue, right.queue);
    std::swap(this->current, right.current);
    return *this;
}


/* ************************************************************************** */
}
