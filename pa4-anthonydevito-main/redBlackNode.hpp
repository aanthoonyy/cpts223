#pragma once
#include "inventoryRecord.hpp"
    

template<typename T>
class RBNode {
public:
    // RBNode() {
    //     left = nullptr;
    //     right = nullptr;
    //     color = 0;
    // }
    // RBNode(const T& newData) {
    //     data = newData;
    //     left = nullptr;
    //     right = nullptr;
    //     color = 0;
    // }
    RBNode() : data{}, left{nullptr}, right{nullptr}, color{0} {}

    RBNode(const T& newData, RBNode<T>* lt = nullptr, RBNode<T>* rt = nullptr, int c = 0)
        : data{newData}, left{lt}, right{rt}, color{c} {}

    RBNode(T&& newData, RBNode<T>* lt = nullptr, RBNode<T>* rt = nullptr, int c = 0)
        : data{std::move(newData)}, left{lt}, right{rt}, color{c} {}

    ~RBNode() {}

    // RBNode(const T& theData, RBNode* lt = nullptr, RBNode* rt = nullptr, int c = 0) 
    //     : data{ theData }, left{ lt }, right{ rt }, color{ c } {}
        
    // RBNode(T&& theData, RBNode* lt = nullptr, RBNode* rt = nullptr, int c = 0) 
    //     : data{ move(theData) }, left{ lt }, right{ rt }, color{ c } {}



    T getData() const { return data; }

    void setData(const T& newData) { data = newData; }

    RBNode<T>* getLeft() const { 
            return left; }

    void setLeft(RBNode<T>* newLeft) { left = newLeft; }

    RBNode<T>* getRight() const { return right; }

    void setRight(RBNode<T>* newRight) { right = newRight; }

    int getColor() const { return color; }
    
    void setColor(int newColor) { color = newColor; }

    

//private:
    T data;
    RBNode<T>* left;
    RBNode<T>* right;
    int color; // 0 for black, 1 for red

};



