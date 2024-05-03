#include <stdexcept>
#include <iostream>
namespace lasd {

/* ************************************************************************** */

    //------------ VECTOR -----------------

    // Specific constructors
    template <typename Data>
    Vector<Data>::Vector(const ulong newsize) {
        size = newsize;
        elem = new Data[size]{};
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& cont) : Vector(cont.Size()) {
        ulong index = 0;

        cont.Traverse(
                [this, &index](const Data& dat){
                    elem[index++] = dat;
                });
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& cont) : Vector(cont.Size()) {
        ulong index = 0;

        cont.Map(
                [this, &index](Data& dat){
                    elem[index++] = std::move(dat);
                });
    }

    // Copy constructor
    template <typename Data>
    Vector<Data>::Vector(const Vector& vec) {
        size = vec.size;

        elem = new Data[size];

        std::copy(vec.elem, vec.elem + size, elem);
    }

    // Move constructor
    template <typename Data>
    Vector<Data>::Vector(Vector&& vec) noexcept {
    std::swap(size, vec.size);

    std::swap(elem, vec.elem);
}

// Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
    Vector<Data> *tmpvec = new Vector(vec);
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

// Move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept {
std::swap(size, vec.size);
std::swap(elem, vec.elem);
return *this;
}

// Comparison operators
template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept {
if (size != vec.size)
return false;

for (ulong i = 0; i < size; i++){
if (elem[i] != vec.elem[i])
return false;
}

return true;
}

template <typename Data>
inline bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept {
return !(*this == vec);
}

// Specific member function (inherited from ClearableContainer)
template <typename Data>
void Vector<Data>::Clear() {
    delete[] elem;
    elem = nullptr;
    size = 0;
}

// Specific member function (inherited from ResizableContainer)
template <typename Data>
void Vector<Data>::Resize(const ulong newsize) {
    if (newsize == 0)
        Clear();
    else if (size != newsize) {
        Data *tmpelem = new Data[newsize] {};
        ulong minsize = (size < newsize) ? size : newsize;

        for (ulong i = 0; i < minsize; i++)
            std::swap(elem[i], tmpelem[i]);

        std::swap(elem, tmpelem);
        size = newsize;
        delete[] tmpelem;
    }
}

// Specific member functions (inherited from LinearContainer)

template <typename Data>
const Data& Vector<Data>::operator[](const ulong index) const {
    if (index > size)
        throw std::out_of_range("Indice (" + std::to_string(index) + ") maggiore della grandezza massima (" + std::to_string(size) + ").");
    else
        return elem[index];
}

template <typename Data>
Data& Vector<Data>::operator[](const ulong index) {
    if (index > size)
        throw std::out_of_range("Indice (" + std::to_string(index) + ") maggiore della grandezza massima (" + std::to_string(size) + ").");
    else
        return elem[index];
}

template <typename Data>
const Data& Vector<Data>::Front() const {
    if (Container::Empty())
        throw std::length_error("Vettore vuoto.");

    return elem[0];
}

template <typename Data>
Data& Vector<Data>::Front() {
    if (Container::Empty())
        throw std::length_error("Vettore vuoto.");

    return elem[0];
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if (Container::Empty())
        throw std::length_error("Vettore vuoto.");

    return elem[size - 1];
}

template <typename Data>
Data& Vector<Data>::Back() {
    if (Container::Empty())
        throw std::length_error("Vettore vuoto.");

    return elem[size - 1];
}

// ----------------- SORTABLE VECTOR --------------------

// Specific constructors
template <typename Data>
SortableVector<Data>::SortableVector(const ulong newsize) noexcept {
size = newsize;
elem = new Data[size]{};
}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& cont) noexcept : SortableVector(cont.Size()) {
ulong index = 0;

cont.Traverse(
[this, &index](const Data& dat){
elem[index++] = dat;
});
}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& cont) noexcept : SortableVector(cont.Size()) {
ulong index = 0;

cont.Map(
[this, &index](Data& dat){
elem[index++] = std::move(dat);
});
}

// Copy constructor
template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector& vec) {
    size = vec.size;

    elem = new Data[size];

    std::copy(vec.elem, vec.elem + size, elem);
}

// Move constructor
template <typename Data>
SortableVector<Data>::SortableVector(SortableVector&& vec) noexcept {
std::swap(size, vec.size);

std::swap(elem, vec.elem);
}

// Copy assignment
template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vec) {
    SortableVector<Data> *tmpvec = new SortableVector(vec);
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

// Move assignment
template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& vec) noexcept {
std::swap(size, vec.size);
std::swap(elem, vec.elem);
return *this;
}
/* ************************************************************************** */

};
