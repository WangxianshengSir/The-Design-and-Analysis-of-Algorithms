#include <iostream>
using namespace std;

template <typename T>
struct AVLTreeNode
{
    AVLTreeNode(T val,AVLTreeNode *l,AVLTreeNode *r)
    :value(val),lChild(l),rChild(r),height(0){}
        int height;
        T value;
        AVLTreeNode *lChild;
        AVLTreeNode *rChild;
};

template <typename T>
class AVLTree
{
    public:
        void insert(T value);
        AVLTreeNode<T> *search_iterate(T value);
        void remove(T value);
        void destroy(); 
        int height();
    private:
        AVLTreeNode<T> *root;
        int height(AVLTreeNode<T> *pNode);
        void insert(AVLTreeNode<T> *pNode,T value);
        void remove(AVLTreeNode<T> *pNode,T value);
        AVLTreeNode<T> *RRotation(AVLTreeNode<T> *pNode,T value);
        AVLTreeNode<T> *LRotation(AVLTreeNode<T> *pNode,T value);
        AVLTreeNode<T> *RLRotation(AVLTreeNode<T> *pNode,T value);
        AVLTreeNode<T> *LRRotation(AVLTreeNode<T> *pNode,T value);
};
template <typename T>
int AVLTree<T>::height(AVLTreeNode<T> *pNode)
{
    if(pNode==nullptr)
    {
        pNode=new AVLTreeNode()
    }
}