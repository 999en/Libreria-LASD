#include "list.hpp"
namespace lasd {

/* ************************************************************************** */

    // Specific constructors
    template <typename Data>
    List<Data>::Node::Node(Data &&dat) noexcept {
        std::swap(element, dat);
    }

    // Move constructor
    template <typename Data>
    List<Data>::Node::Node(Node &&node) noexcept {
        std::swap(element, node.element);
        std::swap(next, node.next);
    }

    // Destructor
    template <typename Data>
    List<Data>::Node::~Node(){
        delete next;
    }

    // Comparison operators
    template <typename Data>
    bool List<Data>::Node::operator==(const Node &node) const noexcept {
        return (element == node.element) \
        && ((next == nullptr && node.next == nullptr) || (next != nullptr && node.next != nullptr) && ((*next) == (*node.next)));
    }

    template <typename Data>
    inline bool List<Data>::Node::operator!=(const Node &node) const noexcept {
        return !(*this == node);
    }

    // Specific member functions
    template <typename Data>
    typename List<Data>::Node* List<Data>::Node::Clone(Node* tail) {
        if (next == nullptr) 
            return tail;
        else {
            Node *node = new Node(element);
            node -> next = next -> Clone(tail);
            return node;
        }
    }


    // Specific constructor
    template <typename Data>
    List<Data>::List(const TraversableContainer<Data>& cont) {
        cont.Traverse(
            [this](const Data& data) {
                InsertAtBack(data);
            });
    }

    template <typename Data>
    List<Data>::List(MappableContainer<Data>&& cont) {
        cont.Map(
            [this](Data& data) {
                InsertAtBack(std::move(data));
            });
    }

    // Copy constructor
    template <typename Data>
    List<Data>::List(const List<Data>& list) {
        if (list.tail != nullptr) {
            tail = new Node(*list.tail);
            head = list.head -> Clone(tail);
            size = list.size;
        }
    }

    // Move constructor
    template <typename Data>
    List<Data>::List(List<Data>&& list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
    }

    // Destructor
    template <typename Data>
    List<Data>::~List() {
        delete head;
    }

    // Copy assignment
    template <typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& list) {
        if (size <= list.size) {
            if (tail == nullptr) {
                List<Data> *tmplist = new List<Data>(list);
                std::swap(*tmplist, *this);
                delete tmplist;
            } else {
                Node *oldcur = list.head;
                for (Node *newcur = head; newcur != nullptr; oldcur = oldcur -> next, newcur = newcur -> next) {
                    newcur -> element = oldcur -> element;
                }

                if (oldcur != nullptr) {
                    Node *newtail = new Node(*list.tail);
                    tail -> next = oldcur -> Clone(newtail);
                    tail = newtail;
                }
            }
        } else {
            if (list.tail == nullptr) {
                delete head;
                head = tail = nullptr;
            } else {
                Node *newcur = head;
                for(Node *oldcur = list.head; oldcur != nullptr; oldcur = oldcur -> next, tail = newcur, newcur = newcur -> next) {
                    newcur -> element = oldcur -> element;
                }

                delete newcur;
                tail -> next = nullptr;
            }
        }
        size = list.size;
        return *this;
    }

    // Move assignment
    template <typename Data>
    List<Data>& List<Data>::operator=(List<Data>&& list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);

        return *this;
    }

    // Comparison operators
    template <typename Data>
    bool List<Data>::operator==(const List<Data>& list) const noexcept {
        if (size != list.size)
            return false;
        else {
            Node *cur = head;
            Node *listcur = list.head;

            while (cur != nullptr) {
                if(cur -> element != listcur -> element)
                    return false;
            
                cur = cur -> next;
                listcur = listcur -> next;
            }
        }

        return true;
    }

    template <typename Data>
    inline bool List<Data>::operator!=(const List<Data>& list) const noexcept {
        return !(*this == list);
    }

    // Specific member functions
    template <typename Data>
    void List<Data>::InsertAtFront(const Data& data) {
        Node *newnode = new Node(data);
        newnode -> next = head;
        head = newnode;

        if (tail == nullptr)
            tail = head;

        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtFront(Data&& data) {
        Node *newnode = new Node(std::move(data));
        newnode -> next = head;
        head = newnode;

        if (tail == nullptr)
            tail = head;

        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront() {
        if (head != nullptr){
            Node *front = head;
            if (tail == head) {
                head = tail = nullptr;
            } else {
                head = head -> next;
            }
            --size;
            front -> next = nullptr;
            delete front;
        } else {
            throw std::length_error("Errore: lista vuota!");
        }
    }

    template <typename Data>
    Data List<Data>::FrontNRemove() {
        if (head != nullptr) {
            Node *front = head;
            if (tail == head) {
                head = tail = nullptr;
            } else {
                head = head -> next;
            }

            --size;
            front -> next = nullptr;
            Data dat(std::move(front->element));
            delete front;
            return dat;
        } else {
            throw std::length_error("Errore: lista vuota!");
        }
    }

    template <typename Data>
    void List<Data>::InsertAtBack(const Data& data) {
        Node *end = new Node(data);
        if (tail == nullptr) {
            head = end;
        } else {
            tail -> next = end;
        }
        tail = end;
        ++size;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data&& data) {
        Node *end = new Node(std::move(data));
        if (tail == nullptr) {
            head = end;
        } else {
            tail -> next = end;
        }
        tail = end;
        ++size;
    }

    // Specific member function (inherited from ClearableContainer)
    template <typename Data>
    void List<Data>::Clear() {
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    // Specific member functions (inherited from DictionaryContainer)
    template <typename Data>
    bool List<Data>::Insert(const Data& data) {
        Node *current = head;

        while(current != nullptr) {
            if(current->element == data)
                return false;
            current = current->next;
        }

        InsertAtBack(data);
        return true;
    }

    template <typename Data>
    bool List<Data>::Insert(Data&& data) {
        Node *current = head;
        
        while(current != nullptr) {
            if(current->element == data)
                return false;
            current = current->next;
        }

        InsertAtBack(std::move(data));
        return true;
    }

    template <typename Data>
    bool List<Data>::Remove(const Data& data) {
        Node* last = nullptr;

        for(Node** cur = &head; *cur != nullptr; last = *cur, cur = &((*cur) -> next)) {
            if((*cur) -> element == data) {
                Node* node = *cur;
                *cur = node -> next;
                node -> next = nullptr;
                delete node;
                size--;

                if (tail == node) {
                    tail = last;
                }
                return true;
            }
        }

        return false;
    }
    
    // Specific member functions (inherited from LinearContainer)
    template <typename Data>
    const Data& List<Data>::operator[](const ulong index) const {
        if (index < size) {
            Node *cur = head;
            for (ulong i = 0; i < index; i++, cur = cur -> next) {}
            return cur -> element;
        } else 
            throw std::out_of_range("Indice (" + std::to_string(index) + ") maggiore della grandezza massima (" + std::to_string(size - 1) + ").");
    }

    template <typename Data>
    Data& List<Data>::operator[](const ulong index) {
        if (index < size) {
            Node *cur = head;
            for (ulong i = 0; i < index; i++, cur = cur -> next) {}
            return cur -> element;
        } else 
            throw std::out_of_range("Indice (" + std::to_string(index) + ") maggiore della grandezza massima (" + std::to_string(size - 1) + ").");
    }

    template <typename Data>
    const Data& List<Data>::Front() const {
        if (head != nullptr){
            return head -> element;
        } else  
            throw std::length_error("Lista vuota.");
    }

    template <typename Data>
    Data& List<Data>::Front() {
        if (head != nullptr){
            return head -> element;
        } else  
            throw std::length_error("Lista vuota.");
    }

    template <typename Data>
    const Data& List<Data>::Back() const {
        if (tail != nullptr){
            return tail -> element;
        } else  
            throw std::length_error("Lista vuota.");
    }

    template <typename Data>
    Data& List<Data>::Back() {
        if (tail != nullptr){
            return tail -> element;
        } else  
            throw std::length_error("Lista vuota.");
    }

    // Specific member function (inherited from TraversableContainer)
    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun fun) const {
        PreOrderTraverse(fun,head);
    }

    template <typename Data>
    inline void List<Data>::PreOrderTraverse(TraverseFun fun) const{
    PreOrderTraverse(fun, head);
    }

    template <typename Data>
    inline void List<Data>::PostOrderTraverse(TraverseFun fun) const{
        PostOrderTraverse(fun, head);
    }

    // Auxiliary member functions (List) (for TraversableContainer)

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, const Node *current) const{
        for (; current != nullptr; current = current->next){
            fun(current->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, const Node *current) const{
        if (current != nullptr){
            PostOrderTraverse(fun, current->next);
            fun(current->element);
        }
    }

    // Specific member function (inherited from MappableContainer)
    template <typename Data>
    void List<Data>::Map(MapFun fun) {
        PreOrderMap(fun, head);
    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun) {
        PreOrderMap(fun, head);
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun) {
        PostOrderMap(fun, head);
    }

    // Auxiliary member functions (List) (for MappableContainer)
    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node *current) {
        for (; current != nullptr; current = current->next){
            fun(current->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node *current) {
        if (current != nullptr){
            PostOrderMap(fun, current->next);
            fun(current->element);
        }
    }
/* ************************************************************************** */

}
