
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class TraversableContainer : public virtual TestableContainer<Data>{
        // Must extend TestableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~TraversableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        TraversableContainer& operator=(const TraversableContainer& val) = delete;

        // Move assignment
        TraversableContainer& operator=(TraversableContainer&& val) noexcept = delete;

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const TraversableContainer& val) const noexcept = delete;
        bool operator!=(const TraversableContainer& val) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        using TraverseFun = std::function<void(const Data &)>;

        virtual void Traverse(TraverseFun) const = 0; // la funzione traverse verrà implementata in modo diverso in base a quale classe estende questa

        template <typename Accumulator>
        using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

        template <typename Accumulator>
        inline Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TestableContainer)

        inline bool Exists(const Data &) const noexcept override; // Override TestableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class PreOrderTraversableContainer : public virtual TraversableContainer<Data>{
        // Must extend TraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~PreOrderTraversableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer& val) = delete;

        // Move assignment
        PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&& val) noexcept = delete;

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const PreOrderTraversableContainer& val) const noexcept = delete;
        bool operator!=(const PreOrderTraversableContainer& val) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        using typename TraversableContainer<Data>::TraverseFun;

        virtual void PreOrderTraverse(TraverseFun) const = 0;

        template <typename Accumulator>
        using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        template <typename Accumulator>
        inline Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        virtual void Traverse(TraverseFun) const override;

    };

/* ************************************************************************** */

    template <typename Data>
    class PostOrderTraversableContainer : public virtual TraversableContainer<Data>{
        // Must extend TraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~PostOrderTraversableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const PostOrderTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.
        bool operator!=(const PostOrderTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.

        /* ************************************************************************ */

        // Specific member function

        using typename TraversableContainer<Data>::TraverseFun;

        virtual void PostOrderTraverse(TraverseFun) const = 0;

        template <typename Accumulator>
        using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        template <typename Accumulator>
        inline Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class InOrderTraversableContainer : public virtual TraversableContainer<Data>{
        // Must extend TraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~InOrderTraversableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        InOrderTraversableContainer& operator=(const InOrderTraversableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        InOrderTraversableContainer& operator=(InOrderTraversableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const InOrderTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.
        bool operator!=(const InOrderTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.

        /* ************************************************************************ */

        // Specific member function

        using typename TraversableContainer<Data>::TraverseFun;

        virtual void InOrderTraverse(TraverseFun) const = 0;

        template <typename Accumulator>
        using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        template <typename Accumulator>
        inline Accumulator InOrderFold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class BreadthTraversableContainer : public virtual TraversableContainer<Data>{
        // Must extend TraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~BreadthTraversableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        BreadthTraversableContainer& operator=(const BreadthTraversableContainer& val) =  delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        BreadthTraversableContainer& operator=(BreadthTraversableContainer&& val) noexcept =  delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const BreadthTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.
        bool operator!=(const BreadthTraversableContainer& val) const noexcept = delete; // Comparison of abstract types might be possible.

        /* ************************************************************************ */

        // Specific member function

        using typename TraversableContainer<Data>::TraverseFun;

        virtual void BreadthTraverse(TraverseFun) const = 0;

        template <typename Accumulator>
        using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

        template <typename Accumulator>
        inline Accumulator BreadthFold(FoldFun<Accumulator>, Accumulator) const;

        /* ************************************************************************ */

        // Specific member function (inherited from TraversableContainer)

        virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

    };

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
