
namespace lasd {

/* ************************************************************************** */

    // Copy assignment
    template <typename Data>
    inline StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stk) {
        List<Data>::operator=(stk);
        return *this;
    }

    // Move assignment
    template <typename Data>
    inline StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stk) noexcept {
    List<Data>::operator=(std::move(stk));
    return *this;
}

// Comparison operators
template <typename Data>
inline bool StackLst<Data>::operator==(const StackLst<Data>& stk) const noexcept {
return List<Data>::operator==(stk);
}

template <typename Data>
inline bool StackLst<Data>::operator!=(const StackLst<Data>& stk) const noexcept {
return List<Data>::operator!=(stk);
}

// Specific member functions (inherited from Stack)
template <typename Data>
inline const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

template <typename Data>
inline Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

template <typename Data>
inline void StackLst<Data>::Pop() {
    return List<Data>::RemoveFromFront();
}

template <typename Data>
inline Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
inline void StackLst<Data>::Push(const Data& data) {
    return List<Data>::InsertAtFront(data);
}

template <typename Data>
inline void StackLst<Data>::Push(Data&& data) {
    return List<Data>::InsertAtFront(std::move(data));
}

/* ************************************************************************** */

}
