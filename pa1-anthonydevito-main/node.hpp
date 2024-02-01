#pragma once

template <typename NODETYPE>
class Node {
    public:
        Node(NODETYPE &newData) : pData(newData), pNext(nullptr) {}
        NODETYPE pData;
        Node<NODETYPE> *pNext;
};