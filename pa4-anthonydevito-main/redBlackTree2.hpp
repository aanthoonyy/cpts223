#include "redBlackNode.hpp"
#include "inventoryRecord.hpp"
using namespace std;

template <typename T>
class RBTree {
public:
    RBTree(){

    }
    explicit RBTree( const T & negInf )
    {
        cout << "calling constructor" << endl;
        nullNode    = new RBNode<T>;
        nullNode->left = nullNode->right = nullNode;
        
        header      = new RBNode<T>{ negInf };
        header->left = header->right = nullNode;
    }

    RBTree( const RBTree<T> & rhs )
    {
        nullNode    = new RBNode<T>;
        nullNode->left = nullNode->right = nullNode;
        
        header      = new RBNode<T>{ rhs.header->data };
        header->left = nullNode;
        header->right = clone( rhs.header->right );
    }

    RBTree( RBTree<T> && rhs )
      : nullNode{ rhs.nullNode }, header{ rhs.header }
    {
        rhs.nullNode = nullptr;
        rhs.header = nullptr;
    }

    ~RBTree( )
    {
        //Empty( );
        delete nullNode;
        delete header;
    }
    
    /**
     * Deep copy.
     */
    RBTree<T> & operator=( const RBTree<T> & rhs )
    {
        RBTree<T> copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
        
    /**
     * Move.
     */
    RBTree<T> & operator=( RBTree<T> && rhs )
    {
        std::swap( header, rhs.header );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }

    void insert(const T& newData) {
        //root = insertPrivate(newData);
        RBNode<T>* new_node = new RBNode<T>(newData);
        insertPrivate(new_node);
    }
    
    void printTree() {
        
       //printTree(root);
       
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
        return findMin(root->data);
    }

    RBNode<T> findMax(){
    return findMax(root->data);
    }

    RBNode<T>* getRoot()
    {
        return root;
    }


    RBNode<T>* clone(RBNode<T> *x) const{
        if (x == x->left)
            return nullNode;
        else
            return new RBNode<T>{x->data, clone(x->left), clone(x->right), x->color};
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
    //     return height(node->left) - height(node->getRight());
    // }

    // void updateHeight(RBNode<T>* node) {
    //     if (node == nullptr) {
    //         return;
    //     }
    //     node->setHeight(1 + std::max(height(node->left), height(node->getRight())));
    // }

    RBNode<T>* rightRotate(RBNode<T>* &k2) {
        RBNode<T>* k1 = k2->left;
        RBNode<T>* T2 = k1->right;
        k1->right = k2;
        k2->left = T2;
        //updateHeight(y);
        //updateHeight(x);
        k2 = k1;
        // return k1;
    }

    RBNode<T>* leftotate(RBNode<T>* &k2) {
        RBNode<T>* k1 = k2->right;
        RBNode<T>* T2 = k1->left;
        k1->left = k2;
        k2->right = T2;
        //updateHeight(y);
        //updateHeight(x);
        k2 = k1;
        // return k1;
    }

    RBNode<T> *rotate(const T &item, RBNode<T>* theParent){
        
        RBNode<T> *tempLeft = theParent->left;
        RBNode<T>*tempRight = theParent->right;
        if (item < theParent->data){

            item < theParent->left->data ?
                leftotate(tempLeft) :
                rightRotate(tempLeft);
            theParent->left = tempLeft;
            return theParent->left;
        }
  
        else{
            item < theParent->right->data ?
                leftotate(tempRight) :
                rightRotate(tempRight);
                theParent->right = tempRight;
            return theParent->right;
        }
        
    }
    
    RBNode<T>* insertPrivate(RBNode<T>* node) {
    current = parent = grand = header;
    nullNode->data = node->data;

    while (current->data != node->data)
    {
        great = grand;
        grand = parent;
        parent = current;
        // i added -> data
        current = node->data < current->data ? current->left : current->right;

        if (current->left->color == 1 && current->right->color == 1){
            handleReorient(node);
        }
    }

    if (current != nullNode)
    {
        return nullptr;
    }

    //current = new RBNode<T>(node, nullNode, nullNode);
    current = new RBNode<T>;
    //i added ->data
    if (node->data < parent->data) {
        parent->left = current;
    }
    else {
        parent->right = current;
    }

    handleReorient(node);

    return current;
    }

    void handleReorient(RBNode<T>* item)
    {
        current->color = (1);
        current->left->color = (0);
        current->right->color = (0);

        if (parent->color == 1){
            grand->color = 1;
        if (item->data < grand->data != item->data < parent->data)
        {
            parent = rotate(item, grand);
        }
        current = rotate(item, grand);
        current->color = (0);
        }
        header->right->color= (0);
    }


    RBNode<T>* findMax(RBNode<T>* node) {
    RBNode<T>* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
    }


};


