
namespace lasd {

/* ************************************************************************** */

    // Move constructor
    template<typename Data>
    StackVec<Data>::StackVec(StackVec&& stk) noexcept : Vector<Data>(std::move(stk)) {
        std::swap(index, stk.index);
    }

    // Copy assignment
    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(const StackVec& stk) {
        Vector<Data>::operator=(stk);
        index = stk.index;
        return *this;
    }

    // Move assignment
    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(StackVec&& stk) noexcept {
    Vector<Data>::operator=(std::move(stk));
    std::swap(index, stk.index);
    return *this;
}

// Comparison operators
template<typename Data>
bool StackVec<Data>::operator==(const StackVec& stk) const noexcept {
if (index == stk.index) {
for (ulong i = 0; i < index; i++) {
if (elem[i] != stk.elem[i]) {
return false;
}
}

return true;
} else
return false;
}

template<typename Data>
inline bool StackVec<Data>::operator!=(const StackVec& stk) const noexcept {
return !(*this == stk);
}

// Specific member functions (inherited from Stack)
template<typename Data>
const Data& StackVec<Data>::Top() const {
    if (index != 0) {
        return elem[index - 1];
    } else {
        throw std::length_error("Errore: stack vuoto.");
    }
}

template<typename Data>
Data& StackVec<Data>::Top() {
    if (index != 0) {
        return elem[index - 1];
    } else {
        throw std::length_error("Errore: stack vuoto.");
    }
}

template<typename Data>
void StackVec<Data>::Pop() {
    if (index != 0) {
        Reduce();
        --index;
    } else {
        throw std::length_error("Errore: stack vuoto.");
    }
}

template<typename Data>
Data StackVec<Data>::TopNPop() {
    if (index != 0) {
        Reduce();
        return std::move(elem[--index]);
    } else {
        throw std::length_error("Errore: stack vuoto.");
    }
}

template<typename Data>
void StackVec<Data>::Push(const Data& data) {
    Expand();
    elem[index++] = data;
}

template<typename Data>
void StackVec<Data>::Push(Data&& data) {
    Expand();
    elem[index++] = std::move(data);
}

// Specific member function (inherited from Container)
template<typename Data>
inline bool StackVec<Data>::Empty() const noexcept {
return (index == 0);
}

template<typename Data>
inline ulong StackVec<Data>::Size() const noexcept {
return index;
}


// Specific member function (inherited from ClearableContainer)
template<typename Data>
void StackVec<Data>::Clear() {
    index = 0;
    Vector<Data>::Resize(1);
}

// Auxiliary member functions
template<typename Data>
void StackVec<Data>::Expand() {
    if (index == size)
        Vector<Data>::Resize(size * 2);
}

template<typename Data>
void StackVec<Data>::Reduce() {
    if (index == size/4)
        Vector<Data>::Resize(size / 2);
}

/* ************************************************************************** */

}
