/* 
 * File:   main.cpp
 * Author: lun
 *
 * Created on 2012年11月13日, 上午11:44
 */

#include <cstdlib>
#include <iostream>

const bool RED=0;
const bool BLACK=1;

using namespace std;

//template <typename Type>
class RBTree
{
public:
    RBTree():root(nil){root->p=nil;}
    void insert(int d);
    void removed(int d);
    
private:
        struct Node{
            bool color;
            int data;
            Node *left;
            Node *right;
            Node *p;
            Node(const int &d,bool c=BLACK,Node *l=NULL,Node *r=NULL,Node *pp=NULL):\
            data(d),color(c),left(l),right(r),p(pp) {}
            
        };
        Node *root;
        static Node *nil;
    
        void insert(int d,Node* &x)
        {
            Node *t=x;
            while(t!=nil)
            {
                if(d>t->data)
                    t=t->right;
                else if(d<t->data)
                    t=t->left;
            }
            t=new Node(d);
            t->left=t->right=nil;
            t->p=nil;
        }
};

RBTree::Node *RBTree::nil=new RBTree::Node(0);

/*
 * 
 */
   
int main(int argc, char** argv)
{
    return 0;
}

