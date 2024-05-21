#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

    // Comparison operators

    template <typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& val) const {
        if (size != val.size)
            return false;

        for(ulong i = 0; i < size; i++){
            if(operator[](i) != val[i])
                return false;
        }

        return true;
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& val) const {
        return !(operator==(val));
    }

    // Specific member functions

    template <typename Data>
    inline const Data& LinearContainer<Data>::Front() const {
        if(!Container::Empty())
            return operator[](0);
        else
            throw std::length_error ("Errore: container vuoto!");
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Front() {
        if(!Container::Empty())
            return operator[](0);
        else
            throw std::length_error ("Errore: container vuoto!");
    }

    template <typename Data>
    inline const Data& LinearContainer<Data>::Back() const {
        if(!Container::Empty())
            return operator[](size - 1);
        else
            throw std::length_error ("Errore: container vuoto!");
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back() {
        if(!Container::Empty())
            return operator[](size - 1);
        else
            throw std::length_error ("Errore: container vuoto!");
    }

    // Specific member function (inherited from TraversableContainer)

    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun fun) const {
        PreOrderTraverse(fun);
    }

    // Specific member function (inherited from PreOrderTraversableContainer)

    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
        for (ulong i = 0; i < size; i++)
            fun(operator[](i));
    }

    // Specific member function (inherited from PostOrderTraversableContainer)

    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
        ulong i = size;
        while (i > 0)
            fun(operator[](--i));
    }

    // Specific member function (inherited from MappableContainer)

    template <typename Data>
    inline void LinearContainer<Data>::Map(MapFun fun) {
        PreOrderMap(fun);
    }

    // Specific member function (inherited from PreOrderMappableContainer)

    template <typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFun fun) {
        for (ulong i = 0; i < size; i++)
            fun(operator[](i));
    }

    // Specific member function (inherited from PostOrderMappableContainer)

    template <typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun fun) {
        for(ulong i = size - 1; i > 0; i--)
            fun(operator[](i));
    }


    // Comparison operators

    template<typename Data>
    inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& val) const {
        if (size != val.size)
            return false;

        for(ulong i = 0; i < size; i++){
            if(operator[](i) != val[i])
                return false;
        }

        return true;
    }

    template <typename Data>
    inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& val) const {
        return !(operator==(val));
    }

    // Specific member function

    template <typename Data>
    void SortableLinearContainer<Data>::Sort() noexcept {
        if (!Container::Empty())
            QuickSort(0, size - 1);
    }

    template <typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept {
        if (p < r){
            ulong q = Partition(p, r);
            QuickSort(p, q);
            QuickSort(q+1, r);
        }
    }

    template <typename Data>
    ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept {
        Data x = operator[](p);
        ulong i = p-1;
        ulong j = r+1;

        do{
            do{
                j--;
            }while(x < operator[](j));
            do{
                i++;
            }while(x > operator[](i));
            if (i < j)
                std::swap(operator[](i), operator[](j));
        }while(i < j);

        return j;
    }
/* ************************************************************************** */

};
