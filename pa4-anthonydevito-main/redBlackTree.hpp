#include "redBlackNode.hpp"
#include "inventoryRecord.hpp"
using namespace std;

template <typename T>
class RBTree {
public:
    RBTree() : root(nullptr) {}

    RBTree(const T& negInf)
    {
        nullNode = new RBNode<T>;
        nullNode->leftr = nullNode->getRight() = nullNode;

        header = new RBNode<T>{negInf};
        header->leftr = header->getRight() = nullNode;
    }

    ~RBTree() {
        clear();
    }

    void insert(const T& newData) {
        root = insertPrivate(newData);
    }

    void printTree() {
        
       printTree(root);
       
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

    RBNode<T> findMin(){
        return findMin(root->getData());
    }

    RBNode<T> findMax(){
    return findMax(root->getData());
    }

    RBNode<T>* getRoot()
    {
        return root;
    }

    RBTree(const RBTree<T> & rhs){
        nullNode = new RBNode<T>;
        nullNode->leftr = nullNode->getRight();
        header = new RBNode<T>{rhs.header->getData()};
        header->leftr = nullNode;
        header->getRight() = clone(rhs.header->getRight());
    }

    RBNode<T>* clone(RBNode<T> *x) const{
        if (x == x->leftr)
            return nullNode;
        else
            return new RBNode<T>{x->getData(), clone(x->leftr), clone(x->getRight()), x->getColor()};
    }


private:
    RBNode<T>* root;
    RBNode<T>* header  = new RBNode<T>;
    RBNode<T>* nullNode = new RBNode<T>;
    RBNode<T>* current = new RBNode<T>;
    RBNode<T>* parent = new RBNode<T>;
    RBNode<T>* grand = new RBNode<T>;
    RBNode<T>* great = new RBNode<T>;

    // int height(RBNode<T>* node) const {
    //     if (node == nullptr) {
    //         return -1;
    //     }
    //     return node->getHeight();
    // }

    // int balanceFactor(RBNode<T>* node) const {
    //     if (node == nullptr) {
    //         return 0;
    //     }
    //     return height(node->leftr) - height(node->getRight());
    // }

    // void updateHeight(RBNode<T>* node) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     node->setHeight(1 + std::max(height(node->leftr), height(node->getRight())));
    // }

    RBNode<T>* rightRotate(RBNode<T>* &k2) {
        RBNode<T>* k1 = k2->leftr;
        RBNode<T>* T2 = k1->getRight();
        k1->setRight(k2);
        k2->left = T2;
        //updateHeight(y);
        //updateHeight(x);
        k2 = k1;
        // return k1;
    }

    RBNode<T>* leftRotate(RBNode<T>* &k2) {
        RBNode<T>* k1 = k2->getRight();
        RBNode<T>* T2 = k1->leftr;
        k1->left = k2;
        k2->setRight(T2);
        //updateHeight(y);
        //updateHeight(x);
        k2 = k1;
        // return k1;
    }

    RBNode<T> *rotate(const T &item, RBNode<T>* theParent){
        
        RBNode<T> *tempLeft = theParent->leftr;
        RBNode<T>*tempRight = theParent->getRight();
        if (item < theParent->getData()){

            item < theParent->leftr->getData() ?
                leftRotate(tempLeft) :
                rightRotate(tempLeft);
            theParent->left = tempLeft;
            return theParent->leftr;
        }
  
        else{
            item < theParent->getRight()->getData() ?
                leftRotate(tempRight) :
                rightRotate(tempRight);
                theParent->setRight(tempRight);
            return theParent->getRight();
        }
        
    }
    
    RBNode<T>* insertPrivate(const T& node) {
    current = parent = grand = header;
    nullNode->setData(node);

    while (current->getData() != node)
    {
        great = grand;
        grand = parent;
        parent = current;
        current = node < current->getData() ? current->leftr : current->getRight();
        

        if (current->leftr->getColor() == 1 && current->getRight()->getColor() == 1){
            handleReorient(node);
        }
    }

    if (current != nullNode)
    {
        return nullptr;
    }
    current = new RBNode (node, nullNode, nullNode);

    if (node < parent->getData()) {
        parent->left = current;
        
    }

    else {
        parent->setRight(current);
    }
    handleReorient(node);
    
    }

    void handleReorient(const T &item)
    {
        current->setColor(1);
        current->leftr->setColor(0);
        current->getRight()->setColor(0);

        if (parent->getColor() == 1){
            grand->setColor(1);
        if (item < grand->getData() != item < parent->getData())
        {
            parent = rotate(item, grand);
        }
        current = rotate(item, grand);
        current->setColor(0);
        }
        header->getRight()->setColor(0);
    }


    RBNode<T>* findMax(RBNode<T>* node) {
    RBNode<T>* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
    }


};


