#include <stdexcept>
namespace lasd {
/* ************************************************************************** */
    
    // Specific constructor
    template<typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data>& cont) : Vector<Data>(cont), tail(size) {
        Vector<Data>::Resize(size * 2);
    }

    template<typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data>&& cont) : Vector<Data>(std::move(cont)), tail(size) {
        Vector<Data>::Resize(size * 2);
    }

    // Move constructor
    template<typename Data>
    QueueVec<Data>::QueueVec(QueueVec&& que) noexcept : Vector<Data>(std::move(que)){
        std::swap(head, que.head);
        std::swap(tail, que.tail);
    }
    
    // Copy assignment
    template<typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& que) {
        Vector<Data>::operator=(que);
        head = que.head;
        tail = que.tail;
        return *this;
    }

    // Move assignment
    template<typename Data>
    QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& que) noexcept {
        Vector<Data>::operator=(std::move(que));
        std::swap(head, que.head);
        std::swap(tail, que.tail);
        return *this;
    }

    // Comparison operators
    template<typename Data>
    bool QueueVec<Data>::operator==(const QueueVec& que) const noexcept {
        if (Size() == que.Size()) {
            for (ulong index1 = head, index2 = que.head; index1< tail; ++index1 %= size, ++index2 %= que.size) {
                if (elem[index1] != que.elem[index2])
                    return false;
            }

            return true;
        } else
            return false;
    }

    template<typename Data>
    inline bool QueueVec<Data>::operator!=(const QueueVec& que) const noexcept {
        return !(*this == que);
    }

    // Specific member functions (inherited from Queue)
    template<typename Data>
    const Data& QueueVec<Data>::Head() const {
        if (head != tail) {
            return elem[head];
        } else {
            throw std::length_error("Errore: coda vuota.");
        }
    }

    template<typename Data>
    Data& QueueVec<Data>::Head() {
        if (head != tail) {
            return elem[head];
        } else {
            throw std::length_error("Errore: coda vuota.");
        }
    }

    template<typename Data>
    void QueueVec<Data>::Dequeue() {
        if (head != tail) {
            Reduce();
            ++head %= size;
        } else
            throw std::length_error("Errore: coda vuota.");
    }

    template<typename Data>
    Data QueueVec<Data>::HeadNDequeue() {
        if (head != tail) {
            Reduce();
            Data dat(std::move(elem[head]));
            ++head %= size;
            return dat;
        } else {
            throw std::length_error("Errore: coda vuota.");
        }
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(const Data& data) {
        Expand();
        elem[tail++] = data;
        tail %= size;
    }

    template<typename Data>
    void QueueVec<Data>::Enqueue(Data&& data) {
        Expand();
        elem[tail++] = std::move(data);
        tail %= size;
    }

    // Specific member functions (inherited from Container)
    template<typename Data>
    inline bool QueueVec<Data>::Empty() const noexcept {
        return (head == tail);
    }

    template<typename Data>
    inline ulong QueueVec<Data>::Size() const noexcept {
        return (((size + tail) - head) % size);
    }

    // Specific member function (inherited from ClearableContainer)
    template<typename Data>
    void QueueVec<Data>::Clear() {
        head = tail = 0;
        Vector<Data>::Resize(4);
    }

    // Auxiliary functions
    template<typename Data>
    void QueueVec<Data>::Expand() {
        ulong num = Size();
        if (num + 1 == size) {
            Resize(size * 2, num);
        }
    }

    template<typename Data>
    void QueueVec<Data>::Reduce() {
        ulong num = Size();
        if(num + 1 == size / 4) {
            Resize(size / 2,  num);
        }
    }

    template<typename Data>
    void QueueVec<Data>::Resize(ulong newsize, ulong num) {
        Data *tmpElem = new Data[newsize];
        ulong max = (num <= newsize) ? num : newsize;

        for(ulong index1 = head, index2 = 0; index2 < max; ++index1 %= size, ++index2) {
            std::swap(elem[index1], tmpElem[index2]);
        }

        std::swap(elem, tmpElem);
        delete[] tmpElem;
        head = 0;
        tail = num;
        size = newsize;
    }

/* ************************************************************************** */

}
