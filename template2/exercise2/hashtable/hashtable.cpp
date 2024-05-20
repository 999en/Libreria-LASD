#include "hashtable.hpp"

namespace lasd {

/* ************************************************************************** */

template <>
class Hashable<int> {
    public:
        ulong operator()(const int & dat) const noexcept {
            return dat * dat;
        }
};

template<>
class Hashable<std::string> {
    public:
        ulong operator()(const std::string& dat) const noexcept {
            ulong accumulator = 0;
            for(ulong i = 0; i < dat.length(); i++) {
                accumulator += dat[i] * i;
            }
            return accumulator;
        }
};

template<>
class Hashable<double> {
    public:
        ulong operator()(const double& dat) const noexcept {
            ulong intgpart = floor(dat);
            ulong fracpart = pow(2, 24) * (dat - intgpart);
            return (intgpart * fracpart);
        }
};

template <typename Data>
ulong HashTable<Data>::HashKey(ulong key) const noexcept {
    return (a * key + b) % tableSize;
}

template <typename Data>
HashTable<Data>::HashTable(const HashTable &right) {
    tableSize = right.tableSize;
    size = right.size;
    a = right.a;
    b = right.b;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable &&right) noexcept{
    std::swap(tableSize, right.tableSize);
    std::swap(size, right.size);
    std::swap(a, right.a);
    std::swap(b, right.b);
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable &right) {
    tableSize = right.tableSize;
    size = right.size;
    a = right.a;
    b = right.b;
    return *this;
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable &&right) noexcept {
    std::swap(tableSize, right.tableSize);
    std::swap(size, right.size);
    std::swap(a, right.a);
    std::swap(b, right.b);
    return *this;
}

/* ************************************************************************** */

}