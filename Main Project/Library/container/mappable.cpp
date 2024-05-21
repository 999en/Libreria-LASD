namespace lasd {

/* ************************************************************************** */

    //------------- PRE ORDER ---------------------

    template <typename Data>
    inline void PreOrderMappableContainer<Data>::Map(MapFun fun)  {
        PreOrderMap(fun);
    }

    //------------- POST ORDER ---------------------

    template <typename Data>
    inline void PostOrderMappableContainer<Data>::Map(MapFun fun)  {
        PostOrderMap(fun);
    }

    //------------- IN ORDER ---------------------

    template <typename Data>
    inline void InOrderMappableContainer<Data>::Map(MapFun fun)  {
        InOrderMap(fun);
    }

    //------------- BREADTH ORDER ---------------------

    template <typename Data>
    inline void BreadthMappableContainer<Data>::Map(MapFun fun)  {
        BreadthMap(fun);
    }

/* ************************************************************************** */

}
