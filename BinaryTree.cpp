/*
 *二叉树的个人实现，作为下面平衡二叉树、2-3树、AVL树和B树的基础
 */
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node *l;
    Node *r;
    T val;
};
template <typename T>
class BinaryTree
{
    public :
        void insert(T value){insert(root,value);}
        void remove(T value){remove(root,value);}
        void print(){print(root);}
        BinaryTree();
        BinaryTree(T arr[],int n);
    private:
        void insert(Node<T> *root,T value);
        void remove(Node<T> *root,T value);
        void print(Node<T> *root);
        Node<T> *root;
};
template <typename T>
BinaryTree<T>::BinaryTree()
{
    root=NULL;
}
template <typename T>
BinaryTree<T>::BinaryTree(T arr[],int n)
{
    root=NULL;
    cout<<"construct into"<<endl;
    for(int i=0;i<n;i++)
        insert(root,arr[i]);
    cout<<"construct end"<<endl;
}
template <typename T>
void BinaryTree<T>::insert(Node<T> *root,T value)
{
    cout<<"insert into"<<endl;
    if(root==NULL)
    {
        root=new Node<T>();
        root->l=NULL;
        root->r=NULL;
        root->val=value;

    }else if(root->val>value)
        insert(root->l,value);
    else
        insert(root->r,value);
    cout<<"insert complete";
}
//迭代
template <typename T>
void BinaryTree<T>::remove(Node<T> *root,T value)
{
    if(root->val==value)
    {

    }
     Node<T> *p=root;
     Node<T> *child=root;
     int flag=0;//-1表示左子树，0表示根节点，1表示右子树,判定child的父母节点的左子树还是右子树或本身
     while(child!=NULL)
     {
        if(child->val<value)
        {

            p=child;
            flag=1;
            child=child->r;

        }
        else if(child->val>value)
        {
            p=child;
            flag=-1;
            child=child->l;
        }
        else
        {
            //无子节点
            if(child->l==NULL&&child->r==NULL)
            {
                if(flag==-1)
                    p->l=NULL;
                else
                    p->r=NULL;

                delete child;
                child=NULL;
            }
            //只有一个子节点
            else if(child->l!=NULL)
            {
                    if(flag==-1)
                        p->l=child->l;

                    else if(flag==0)
                    {
                        Node<T> *temp=root;
                        root=root->l;
                        delete temp;


                    }
                    else
                        p->r=child->l;

                    delete child;

            }
            else if(child->r!=NULL)
            {
                    if(flag==-1)
                        p->l=child->r;
                    else if(flag==0)
                    {
                        Node<T> *temp=root;
                        root=root->r;
                        delete temp;
                    }
                    else
                        p->r=child->r;

                    delete child;
            }
            //有两个子节点
            else
            {
                Node<T> *sp=child->r;
                Node<T> *s=sp->l;
                if(s!=NULL)
                    while(s->l!=NULL)
                    {
                        sp=s;
                        s=s->l;
                    }
                else
                {
                    s=sp;
                    sp=child;
                }

                child->val=s->val;
                if(sp->l==s)//一般情况
                {
                    sp->l=s->r;
                }
                else//s为child的右子树
                {
                    sp->r=s->r;
                }
                delete s;
                s=NULL;
            }
        }
     }
}
template <typename T>
void BinaryTree<T>::print(Node<T> *root)
{
    cout<<"print into";
    cout<<root->val<<endl;
    print(root->l);
    print(root->r);
    cout<<endl;
}
int main()
{
    int n=8;
    int arr[]={2,5,7,3,0,9,8,1};
    BinaryTree<int> bt(arr,n);
    cout<<"ddd";
    bt.print();
    return 0;
}
