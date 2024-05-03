
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class TestableContainer : public virtual Container{
        // Must extend Container

    private:

    protected:

    public:

        // Destructor
        virtual ~TestableContainer() = default;

        /* ************************************************************************ */

        // Copy assignment
        TestableContainer& operator=(const TestableContainer& val) = delete;

        // Move assignment
        TestableContainer& operator=(TestableContainer&& val) = delete;

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const TestableContainer& val) const noexcept = delete;
        bool operator!=(const TestableContainer& val) const noexcept = delete;

        /* ************************************************************************ */

        // Specific member function

        virtual bool Exists(const Data& valore) const noexcept = 0;

    };

/* ************************************************************************** */

}

#endif
