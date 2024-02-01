#include "AVLNode.hpp"
#include "cancerData.hpp"
using namespace std;

template <typename T>
class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        clear();
    }

    void insert(const T& newData) {
        root = insert(root, newData);
    }

    void remove(const T& newData) {
        root = remove(root, newData);
    }

    void printTree(int rank, string type) {
        
       printTree(root, rank, type);
       rank++;
    }


    int height(){
        height(root);
    }

    void clear(){
        root = nullptr;
    }

    bool isEmpty() {
        return (root == NULL);
    }

    AVLTree<T> findMin(){
        return findMin(root->getData());
    }

    AVLTree<T> findMax(){
    return findMax(root->getData());
    }

    AVLNode<T>* getRoot()
    {
        return root;
    }
    void printFirst(int &rank, string type)
    {
        printFirst(root, rank, type);
    }
    void printLast(int &rank, string type)
    {
        printLast(root, rank, type);
    }


private:
    AVLNode<T>* root;
    

    int height(AVLNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }
        return node->getHeight();
    }

    int balanceFactor(AVLNode<T>* node) const {
        if (node == nullptr) {
            return 0;
        }
        return height(node->getLeft()) - height(node->getRight());
    }

    void updateHeight(AVLNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        node->setHeight(1 + std::max(height(node->getLeft()), height(node->getRight())));
    }

    AVLNode<T>* rightRotate(AVLNode<T>* y) {
        AVLNode<T>* x = y->getLeft();
        AVLNode<T>* T2 = x->getRight();
        x->setRight(y);
        y->setLeft(T2);
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode<T>* leftRotate(AVLNode<T>* x) {
        AVLNode<T>* y = x->getRight();
        AVLNode<T>* T2 = y->getLeft();
        y->setLeft(x);
        x->setRight(T2);
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode<T>* insert(AVLNode<T>* node, const T& newData) {
    if (node == nullptr) {
        return new AVLNode<T>(newData);
    }

    if (newData <= node->getData()) {
        node->setLeft(insert(node->getLeft(), newData));
    } 
    else {
        node->setRight(insert(node->getRight(), newData));
    }

    updateHeight(node);

    int balance = balanceFactor(node);

    if (balance > 1 && newData <= node->getLeft()->getData()) {
        return rightRotate(node);
    }

    if (balance < -1 && newData > node->getRight()->getData()) {
        return leftRotate(node);
    }

    if (balance > 1 && newData > node->getLeft()->getData()) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    if (balance < -1 && newData <= node->getRight()->getData()) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
    }  

    void remove(AVLNode<T>* node, const T& newData)
        {
            if( node == nullptr )
                return;   // Item not found; do nothing
            
            if( newData < node.getData())
                remove( newData, node->getLeft() );
            else if( node->getData() < newData )
                remove( newData, node->getRight() );
            else if( node->getRight() != nullptr && node->getLeft() != nullptr ) // Two children
            {
                node->getData() = findMin( node->getData() )->getData();
                remove( node->getData(), node->getRight() );
            }
            else
            {
                AVLNode<T> *oldNode = node;
                node = ( node->getLeft() != nullptr ) ? node->getLeft() : node->getRight();
                delete oldNode;
            }
            
            balance( node );
        }

        void printTree(AVLNode<T>* node , int &rank, string type) {
    
                if (node == nullptr) {
                    return;
                } 
                
                printTree(node->getLeft(), rank, type);
                cout << "<" << type <<": " << rank << ". ";
                //<label: rank number. country name. rate>, 
                node->getData().print();

                rank++;
                printTree(node->getRight(), rank, type);

        }

    void printFirst(AVLNode<T>* node, int &rank, string type)
    {
        if (node == nullptr)
        {
            return;
        }
        AVLNode<T>* curr = root;
        while (curr->getLeft() != nullptr) {
        curr = curr->getLeft();
        }
        cout << "<" << type <<": " << rank << ". ";
        curr->getData().print();
    }

    void printLast(AVLNode<T>* node, int &rank, string type)
    {
        if (node == nullptr)
        {
            return;
        }
        AVLNode<T>* curr = root;
        while (curr->getRight() != nullptr) {
        curr = curr->getRight();
        }
        cout << "<" << type <<": " << rank << ". ";
        curr->getData().print();
    }
    
    AVLNode<T>* findMin(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
    }


    AVLNode<T>* findMax(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
    }


};
