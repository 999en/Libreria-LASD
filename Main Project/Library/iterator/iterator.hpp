
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class Iterator {

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        virtual ~Iterator() = default;

        /* ************************************************************************ */

        // Copy assignment
        Iterator& operator=(const Iterator& right) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        Iterator& operator=(Iterator&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const Iterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.
        bool operator!=(const Iterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.

        /* ************************************************************************ */

        // Specific member functions

        virtual const Data& operator*() const = 0;    // (non-mutable version; concrete function must throw std::out_of_range when terminated)

        virtual bool Terminated() const noexcept = 0;     // (concrete function should not throw exceptions)

    };

/* ************************************************************************** */

    template <typename Data>
    class MutableIterator : virtual public Iterator<Data>{

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        virtual ~MutableIterator() = default;

        /* ************************************************************************ */

        // Copy assignment
        MutableIterator& operator=(const MutableIterator& right) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        MutableIterator& operator=(MutableIterator&& right) = delete; // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const MutableIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.
        bool operator!=(const MutableIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.

        /* ************************************************************************ */

        // Specific member functions

        virtual Data& operator*() = 0;   // (mutable version; concrete function must throw std::out_of_range when terminated)

    };

/* ************************************************************************** */

    template <typename Data>
    class ForwardIterator : virtual public Iterator<Data>{

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        virtual ~ForwardIterator() = default;

        /* ************************************************************************ */

        // Copy assignment
        ForwardIterator& operator=(const ForwardIterator& right) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        ForwardIterator& operator=(ForwardIterator&& right) = delete; // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const ForwardIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.
        bool operator!=(const ForwardIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.

        /* ************************************************************************ */

        // Specific member functions

        virtual ForwardIterator& operator++() = 0;  // (concrete function must throw std::out_of_range when terminated)

    };

/* ************************************************************************** */

    template <typename Data>
    class ResettableIterator : virtual public Iterator<Data>{

    private:

        Data* root;

    protected:

        // ...

    public:

        // Destructor
        virtual ~ResettableIterator() = default;

        /* ************************************************************************ */

        // Copy assignment
        ResettableIterator& operator=(const ResettableIterator& right) = delete; // Copy assignment of abstract types should not be possible.

        // Move assignment
        ResettableIterator& operator=(ResettableIterator&& right) = delete; // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const ResettableIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.
        bool operator!=(const ResettableIterator& right) const noexcept = delete; // Comparison of abstract types might not be possible.

        /* ************************************************************************ */

        // Specific member functions

        virtual void Reset() = 0;// (concrete function should not throw exceptions)

    };

/* ************************************************************************** */

}

#endif