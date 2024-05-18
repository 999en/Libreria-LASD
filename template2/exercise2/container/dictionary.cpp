
namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& trav) {
        bool all = true;

        trav.Traverse(
            [this, &all](const Data& dat){
                all &= Insert(dat);
            });

            return all;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& map) noexcept {
        bool all = true;

        map.Map(
            [this, &all](const Data& dat){
                all &= Insert(std::move(dat));
            });

            return all;
    }


    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& trav) {
        bool some = false;

        trav.Traverse(
            [this, &some](const Data& dat){
                some |= Insert(dat);
            });

            return some;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& map) noexcept {
        bool some = false;

        map.Map(
            [this, &some](const Data& dat){
                some |= Insert(std::move(dat));
            });

            return some;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& trav) {
        bool all = true;

        trav.Traverse(
            [this, &all](const Data& dat){
                all &= Remove (dat);
            });

        return all;
    }

    template <typename Data>
    bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& trav) {
        bool some = false;

        trav.Traverse(
            [this, &some](const Data& dat){
                some |= Remove (dat);
            });

        return some;
    }
/* ************************************************************************** */

};