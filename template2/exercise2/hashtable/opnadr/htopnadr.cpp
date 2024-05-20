#include "htopnadr.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize) {
    tableSize = std::pow(2, std::ceil(log2((newSize < 16) ? 16 : newSize)));
    table = new Data[tableSize] {};
    tableFlag = new Flag[tableSize] {};
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> &right) : HashTableOpnAdr(right.Size() * 2) {
    InsertAll(right);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, const TraversableContainer<Data> &right) : HashTableOpnAdr(newSize) {
    InsertAll(right);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> &&right) noexcept : HashTableOpnAdr(right.Size() * 2) {
    InsertAll(std::move(right));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, MappableContainer<Data> &&right) noexcept : HashTableOpnAdr(newSize) {
    InsertAll(std::move(right));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr &right) : HashTable<Data>(right) {
    table = new Data[tableSize] {};
    tableFlag = new Flag[tableSize] {};
    for(ulong i = 0; i < tableSize; i++) {
        table[i] = right.table[i];
        tableFlag[i] = right.tableFlag[i];
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr &&right) noexcept : HashTable<Data>(std::move(right)) {
    std::swap(table, right.table);
    std::swap(tableFlag, right.tableFlag);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &right) {
    HashTable<Data>::operator=(right);
    delete[] table;
    delete[] tableFlag;
    table = new Data[tableSize] {};
    tableFlag = new Flag[tableSize] {};
    for(ulong i = 0; i < tableSize; i++) {
        table[i] = right.table[i];
        tableFlag[i] = right.tableFlag[i];
    }
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&right) noexcept {
    HashTable<Data>::operator=(std::move(right));
    std::swap(table, right.table);
    std::swap(tableFlag, right.tableFlag);
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &right) const noexcept {
    if(size != right.Size()) {
        return false;
    }
    for(ulong i = 0; i < tableSize; i++) {
        if(tableFlag[i] == valid) {
            if(!right.Exists(table[i])) {
                return false;
            }
        }
    }
    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data &element) {
    ulong prob_index = 0;
    if(size * 2 > tableSize) {
        Resize(tableSize * 2);
    }
    ulong index = FindEmpty(element, prob_index);
    if(tableFlag[index] != valid){
        table[index] = element;
        tableFlag[index] = valid;
        ++size;
        return !Remove(++prob_index, element); 
    }
    prob_index = 0;
    return false;
}
        
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data &&element) {
    ulong prob_index = 0;
    if(size * 2 >= tableSize) {
        Resize(tableSize * 2);
    }
    ulong index = FindEmpty(element, prob_index);
    if(tableFlag[index] != valid){
        table[index] = std::move(element);
        tableFlag[index] = valid;
        ++size;
        return !Remove(++prob_index, element); 
    }
    prob_index = 0;
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data &element) {
    ulong prob_index = 0;
    return Remove(prob_index, element);
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &element) const noexcept {
    ulong prob_index = 0;
    ulong index = HashKey(Hashable<Data>()(element));
    return Find(index, prob_index, element);
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong newSize) {
    ulong tmptableSize = (newSize <= 16)? 16 : std::pow(2, std::ceil(log2(newSize)));

    Data* tmpTable = new Data[tmptableSize] {};
    Flag* tmpTableFlag = new Flag[tmptableSize] {}; 

    std::swap(tmptableSize, tableSize);
    std::swap(tmpTable, table);
    std::swap(tmpTableFlag, tableFlag);

    size = 0;
    for(ulong i = 0; i < tmptableSize; i++){
        if(tmpTableFlag[i] == valid) {
            Insert(tmpTable[i]);
        }
    }   
    delete[] tmpTable;
    delete[] tmpTableFlag;
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    for(ulong i = 0; i < tableSize; i++) {
        tableFlag[i] = dirty;
    }
    size = 0;
}

template <typename Data> 
ulong HashTableOpnAdr<Data>::HashKey(const Data& key, ulong& prob_index) const noexcept {
    ulong index = HashKey(Hashable<Data>()(key));
    return (index + tableSize + ((prob_index * prob_index) + prob_index)/2) % tableSize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Find(ulong &index, ulong& prob_index, const Data &element) const noexcept {
    ulong tmp_index = HashKey(element, prob_index);
    ulong jumps = 0;
    do{
        if(jumps == tableSize - 1) {
            return false;
        }
        if((table[tmp_index] == element) && (tableFlag[tmp_index] == valid)) {
            index = tmp_index;
            return true;
        }
        tmp_index = HashKey(element, ++prob_index);
        jumps++;
    } while(!tableFlag[tmp_index] == empt);
    return false;
}

template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data &element, ulong& prob_index) const noexcept {
    ulong tmp_index = HashKey(element, prob_index);
    while((tableFlag[tmp_index] == valid) && (table[tmp_index] != element)) {   
        tmp_index = HashKey(element, ++prob_index);
    }
    return tmp_index;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(ulong& prob_index, const Data &key) noexcept {
    ulong tmp_index;
    if(Find(tmp_index, prob_index, key)){
        tableFlag[tmp_index] = dirty;
        size--;
        prob_index = 0;
        if((size < tableSize / 5) && (tableSize > 16)) {
            Resize(tableSize / 2);
        }
        return true;
    }
    prob_index = 0;
    return false;
}

/* ************************************************************************** */

}