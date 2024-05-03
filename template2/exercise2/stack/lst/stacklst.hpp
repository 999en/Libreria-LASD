
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class StackLst : public virtual Stack<Data>, virtual protected List<Data>{
        // Must extend Stack<Data>,
        //             List<Data>

    private:

    protected:

        // using List<Data>::???;

    public:

        // Default constructor
        inline StackLst() = default;

        /* ************************************************************************ */

        // Specific constructor
        StackLst(const TraversableContainer<Data>& con) : List<Data>(con) {}; // A stack obtained from a TraversableContainer
        StackLst(MappableContainer<Data>&& con) : List<Data>(std::move(con)) {}; // A stack obtained from a MappableContainer

        /* ************************************************************************ */

        // Copy constructor
        inline StackLst(const StackLst& stk) :  List<Data>(stk) {};

        // Move constructor
        inline StackLst(StackLst&& stk) : List<Data>(std::move(stk)) {};

        /* ************************************************************************ */

        // Destructor
        virtual ~StackLst() = default;

        /* ************************************************************************ */

        // Copy assignment
        inline StackLst& operator=(const StackLst<Data>&);

        // Move assignment
        inline StackLst& operator=(StackLst<Data>&&) noexcept;

        /* ************************************************************************ */

        // Comparison operators
        inline bool operator==(const StackLst&) const noexcept;
        inline bool operator!=(const StackLst&) const noexcept;

        /* ************************************************************************ */

        // Specific member functions (inherited from Stack)

        inline const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        inline Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
        inline void Pop() override; // Override Stack member (must throw std::length_error when empty)
        inline Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
        inline void Push(const Data&) override; // Override Stack member (copy of the value)
        inline void Push(Data&&) override; // Override Stack member (move of the value)

        /* ************************************************************************ */

        // Specific member function (inherited from ClearableContainer)

        using List<Data>::Clear;

    protected:

        // Auxiliary functions, if necessary!

    };

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
