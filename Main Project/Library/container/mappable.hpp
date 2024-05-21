
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class MappableContainer : public virtual TraversableContainer<Data>{
        // Must extend TraversableContainer<Data>

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        virtual ~MappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        MappableContainer& operator=(const MappableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        MappableContainer& operator=(MappableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const MappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.
        bool operator!=(const MappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        using MapFun = std::function<void(Data &)>;

        virtual void Map(MapFun) = 0;

    };

/* ************************************************************************** */

    template <typename Data>
    class PreOrderMappableContainer : public virtual MappableContainer<Data>, public virtual PreOrderTraversableContainer<Data> {
        // Must extend MappableContainer<Data>,
        //             PreOrderTraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~PreOrderMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        PreOrderMappableContainer& operator=(const PreOrderMappableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        PreOrderMappableContainer& operator=(PreOrderMappableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const PreOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.
        bool operator!=(const PreOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        using typename MappableContainer<Data>::MapFun;

        inline virtual void PreOrderMap(MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        virtual void Map(MapFun) override; // Override MappableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class PostOrderMappableContainer : public virtual MappableContainer<Data>,
                                       public virtual PostOrderTraversableContainer<Data> {
        // Must extend MappableContainer<Data>,
        //             PostOrderTraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~PostOrderMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        PostOrderMappableContainer& operator=(const PostOrderMappableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        PostOrderMappableContainer& operator=(PostOrderMappableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const PostOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.
        bool operator!=(const PostOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        using typename MappableContainer<Data>::MapFun;

        inline virtual void PostOrderMap(MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        virtual void Map(MapFun) override; // Override MappableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class InOrderMappableContainer : public virtual MappableContainer<Data>, public virtual InOrderTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             InOrderTraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~InOrderMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        InOrderMappableContainer& operator=(const InOrderMappableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        InOrderMappableContainer& operator=(InOrderMappableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const InOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.
        bool operator!=(const InOrderMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        using typename MappableContainer<Data>::MapFun;

        inline virtual void InOrderMap(MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        virtual void Map(MapFun) override; // Override MappableContainer member

    };

/* ************************************************************************** */

    template <typename Data>
    class BreadthMappableContainer : public virtual MappableContainer<Data>, public virtual BreadthTraversableContainer<Data>{
        // Must extend MappableContainer<Data>,
        //             BreadthTraversableContainer<Data>

    private:

    protected:

    public:

        // Destructor
        virtual ~BreadthMappableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        BreadthMappableContainer& operator=(const BreadthMappableContainer& val) = delete; // Copy assignment of abstract types is not possible.

        // Move assignment
        BreadthMappableContainer& operator=(BreadthMappableContainer&& val) noexcept = delete; // Move assignment of abstract types is not possible.

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const BreadthMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.
        bool operator!=(const BreadthMappableContainer& val) const noexcept = delete; // Comparison of abstract types is not possible.

        /* ************************************************************************ */

        // Specific member function

        using typename MappableContainer<Data>::MapFun;

        inline virtual void BreadthMap(MapFun) = 0;

        /* ************************************************************************ */

        // Specific member function (inherited from MappableContainer)

        virtual void Map(MapFun) override; // Override MappableContainer member

    };

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
