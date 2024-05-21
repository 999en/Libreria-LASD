
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class Vector : public virtual ResizableContainer, public virtual LinearContainer<Data>{
        // Must extend ResizableContainer,
        //             LinearContainer<Data>

    private:

    protected:

        using Container::size;
        Data* elem = nullptr;

    public:

        // Default constructor
        Vector() = default;

        /* ************************************************************************ */

        // Specific constructors
        Vector(const ulong); // A vector with a given initial dimension
        Vector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
        Vector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer

        /* ************************************************************************ */

        // Copy constructor
        Vector(const Vector&);

        // Move constructor
        Vector(Vector&&) noexcept;

        /* ************************************************************************ */

        // Destructor
        virtual ~Vector() {
            delete[] elem; // deallochiamo tutti gli elementi
        }

        /* ************************************************************************ */

        // Copy assignment
        Vector& operator=(const Vector&);

        // Move assignment
        Vector& operator=(Vector&&) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const Vector&) const noexcept;
        inline bool operator!=(const Vector&) const noexcept;

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        void Clear() override; // Override ClearableContainer member

        /* ************************************************************************ */

        // Specific member function (inherited from ResizableContainer)

        void Resize(const ulong) override; // Override ResizableContainer member

        /* ************************************************************************ */

        // Specific member functions (inherited from LinearContainer)

        const Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
        Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

        const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
        Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

        const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
        Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

    };

/* ************************************************************************** */

    template <typename Data>
    class SortableVector : public virtual Vector<Data>, public virtual SortableLinearContainer<Data>{
        // Must extend Vector<Data>,
        //             SortableLinearContainer<Data>

    private:

    protected:

        using Vector<Data>::size;
        using Vector<Data>::elem;

    public:

        // Default constructor
        SortableVector() = default;

        /* ************************************************************************ */

        // Specific constructors
        SortableVector(const ulong) noexcept; // A vector with a given initial dimension
        SortableVector(const TraversableContainer<Data>&) noexcept; // A vector obtained from a TraversableContainer
        SortableVector(MappableContainer<Data>&&) noexcept; // A vector obtained from a MappableContainer

        /* ************************************************************************ */

        // Copy constructor
        SortableVector(const SortableVector&);

        // Move constructor
        SortableVector(SortableVector&&) noexcept;

        /* ************************************************************************ */

        // Destructor
        ~SortableVector(){};

        /* ************************************************************************ */

        // Copy assignment
        SortableVector& operator=(const SortableVector&);

        // Move assignment
        SortableVector& operator=(SortableVector&&) noexcept;

        using Vector<Data>::operator[];

    };

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
