#pragma once
#include "cancerData.hpp"
    // template<typename Comparable>
    // class AvlNode
    // {
    //     public:
    //     Comparable element;
    //     AvlNode   *left;
    //     AvlNode   *right;
    //     int       height;

    //     AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
    //       : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
    //     AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
    //       : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }

          
    //     AvlNode *root;
    // };

    

template<typename T>
class AVLNode {
public:
    AVLNode() {
        left = nullptr;
        right = nullptr;
        height = 0;
    }
    AVLNode(const T& newData) {
        data = newData;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
    ~AVLNode() {}


    T getData() const { return data; }

    void setData(const T& newData) { data = newData; }

    AVLNode<T>* getLeft() const { return left; }

    void setLeft(AVLNode<T>* newLeft) { left = newLeft; }

    AVLNode<T>* getRight() const { return right; }

    void setRight(AVLNode<T>* newRight) { right = newRight; }

    int getHeight() const { return height; }
    
    void setHeight(int newHeight) { height = newHeight; }

private:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
    //AVLNode<T> *root;
};



