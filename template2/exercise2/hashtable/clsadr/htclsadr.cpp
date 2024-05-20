#include "htclsadr.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize) {
    tableSize = std::pow(2, std::ceil(log2((newSize <= 16) ? 16 : newSize)));
    table = new lasd::BST<Data>[tableSize] {};
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& right) : HashTableClsAdr(right.Size()) {
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, const TraversableContainer<Data>& right) : HashTableClsAdr(newSize) {
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& right) noexcept : HashTableClsAdr(right.Size()) {
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, MappableContainer<Data>&& right) noexcept : HashTableClsAdr(newSize) {
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& right) : HashTable<Data>(right) {
    table = new lasd::BST<Data>[tableSize] {};
    std::copy(right.table, right.table + tableSize, table);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& right) noexcept : HashTable<Data>(std::move(right)) {
    std::swap(table, right.table);
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& right) {
    HashTable<Data>::operator=(right);
    delete[] table;
    table = new lasd::BST<Data>[tableSize] {};
    for(ulong i = 0; i < tableSize; i++) {
        table[i] = right.table[i];
    }
    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&right) noexcept {
    HashTable<Data>::operator=(std::move(right));
    std::swap(table, right.table);
    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &right) const noexcept {
    bool result = true;
    if(right.size != size) {
        return false;
    }
    for(ulong i = 0; i < tableSize; i++){
        table[i].Traverse(
            [&right, &result](const Data& dat){
                if(!right.Exists(dat)){
                    result = false;
                    return;
                }
            }
        );
        if(!result) {
            return false;
        }
    }
    return true;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data &value) {
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(value));
    result = table[index].Insert(value);
    if(result) {
        size++;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data &&value)
{
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(std::move(value)));
    result = table[index].Insert(std::move(value));
    if(result) {
        size++;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data &value)
{
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(value));
    result = table[index].lasd::BST<Data>::Remove(value);
    if(result) {
        size--;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &value) const noexcept {
    ulong index = HashKey(Hashable<Data>()(value));
    if(table[index].Exists(value)) {
        return true;
    }
    return false;
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong new_size) {
    ulong newTableSize = (new_size <= 16)? 16 : std::pow(2, std::ceil(log2(new_size)));
    size = 0;
    lasd::BST<Data>* newTable = new lasd::BST<Data>[newTableSize] {};
    std::swap(newTable, table);
    std::swap(newTableSize, tableSize);
    for(ulong i = 0; i < newTableSize; i++){
        InsertAll(newTable[i]);
    }
    delete[] newTable;
}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    delete[] table;
    table = new lasd::BST<Data>[tableSize] {};
    size = 0;
}
/* ************************************************************************** */
}