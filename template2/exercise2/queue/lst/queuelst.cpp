
namespace lasd {

/* ************************************************************************** */
    // Copy assignment
    template <typename Data>
    inline QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& que) {
        List<Data>::operator=(que);
        return *this;
    }

    // Move assignment
    template <typename Data>
    inline QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& que) noexcept {
        List<Data>::operator=(std::move(que));
        return *this;
    }

    // Comparison operators
    template <typename Data>
    inline bool QueueLst<Data>::operator==(const QueueLst<Data>& que) const noexcept {
        return List<Data>::operator==(que);
    }

    template <typename Data>
    inline bool QueueLst<Data>::operator!=(const QueueLst<Data>& que) const noexcept {
        return List<Data>::operator!=(que);
    }

    // Specific member functions (inherited from Queue)
    template <typename Data>
    inline const Data& QueueLst<Data>::Head() const {
        return List<Data>::Front();
    }

    template <typename Data>
    inline Data& QueueLst<Data>::Head() {
        return List<Data>::Front();
    }

    template <typename Data>
    inline void QueueLst<Data>::Dequeue() {
        return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    inline Data QueueLst<Data>::HeadNDequeue() {
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(const Data& data) {
        return List<Data>::InsertAtBack(data);
    }

    template <typename Data>
    inline void QueueLst<Data>::Enqueue(Data&& data) {
        return List<Data>::InsertAtBack(data);
    }

/* ************************************************************************** */

}
