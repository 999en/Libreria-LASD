#include "binarytreelnk.hpp"

namespace lasd
{

    /* ************************************************************************** */


    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(TraversableContainer<Data> &&right)
    {
        size = right.Size();
        QueueVec<NodeLnk **> queue;
        queue.Enqueue(&root);
        right.Map(
            [&queue](const Data &dat)
            {
                NodeLnk *&current = *queue.HeadNDequeue();
                current = new NodeLnk(std::move(dat));
                queue.Enqueue(&current->LChild);
                queue.Enqueue(&current->RChild);
            });
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data> &right)
    {
        size = right.Size();
        QueueVec<NodeLnk **> queue;
        queue.Enqueue(&root);
        right.Map(
            [&queue](const Data &dat)
            {
                NodeLnk *&current = *queue.HeadNDequeue();
                current = new NodeLnk(dat);
                queue.Enqueue(&current->LChild);
                queue.Enqueue(&current->RChild);
            });
    }
    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &right)
    {
        if(right.root!=nullptr) {
            root = new NodeLnk(*right.root);
            size = right.Size();
        }     
    }

    template <typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&right) noexcept
    {
        std::swap(root, right.root);
        std::swap(size, right.size);
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk &right)
    {
        Clear();
        if(right.root!=nullptr) {
            root = new NodeLnk(*right.root);
            size = right.Size();
        }    
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data> &BinaryTreeLnk<Data>::operator=(BinaryTreeLnk &&right) noexcept
    {
        std::swap(root, right.root);
        std::swap(size, right.size);
        return *this;
    }

    template <typename Data>
    inline BinaryTreeLnk<Data>::NodeLnk::~NodeLnk()
    {
        if (LChild != nullptr)
        {
            delete LChild;
            LChild = nullptr;
        }
        if (RChild != nullptr)
        {
            delete RChild;
            RChild = nullptr;
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk &right)
    {
        element = right.element;
        LChild = (right.LChild != nullptr) ? new NodeLnk(*right.LChild) : nullptr;
        RChild = (right.RChild != nullptr) ? new NodeLnk(*right.RChild) : nullptr;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk &&right) noexcept
    {
        std::swap(element, right->element);
        std::swap(LChild, right->LChild);
        std::swap(RChild, right->RChild);
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk &right)
    {
        element(right->element);
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk &BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk &&right) noexcept
    {
        std::swap(element, right->element);
        return *this;
    }

    /* ************************************************************************** */

}
