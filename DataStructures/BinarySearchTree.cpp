/* 
 * File:   main.cpp
 * Author: lun
 *
 * Created on 2012年3月9日, 下午1:48
 */

 /*
***********二叉查找树性质**********
**1、若它的左子树不空，则左子树上所有结点的值均小于或者等于它的根结点的值；
**2、若它的右子树不空，则右子树上所有结点的值均大于或者等于它的根结点的值；
**3、它的左、右子树也分别为二叉查找树；
**即它们大小关系满足: 左<=中<=右
***********************************
*/

#include <cstdlib>
#include<iostream>

using namespace std;

template<typename Type>

class BinarySearchTree{
private:
   struct BinaryNode
  {
     Type data;
     BinaryNode *left;
     BinaryNode *right;
     BinaryNode(const Type &theData,BinaryNode *lf,BinaryNode *rt)
     {
        data=theData;left=lf;right=rt;
     }
  };
  
  BinaryNode *root;

   BinaryNode *findMin(BinaryNode *t) const{
      if(t==NULL) return NULL;
      if(t->left==NULL) return t;
      else return findMin(t->left);
   }
   
   BinaryNode *findMax(BinaryNode *t) const{
       if(t==NULL) return NULL;
       if(t->right==NULL) return t;
      else return findMax(t->right);
   }
   
   BinaryNode  * contains(Type x,BinaryNode *t) const{
      if(t==NULL) return NULL;
      else if(x< t->data) return contains(x,t->left);
      else if(x> t->data) return contains(x,t->right);
      return t;
   }
   
   void printTree(BinaryNode * t) const{
       if(t!=NULL)
       {
           printTree(t->left);
           cout<<t->data<<" ";
           printTree(t->right);
       }
   }

  void makeEmpty(BinaryNode * &t){
     if(t!=NULL){
          makeEmpty(t->left);
          makeEmpty(t->right);
          delete(t);
      }    
  }
   
   void insert(Type x,BinaryNode * &t){
        if(t==NULL) t=new BinaryNode(x,NULL,NULL);
        else if(x< t->data) insert(x,t->left);
        else if(x> t->data) insert(x,t->right);
   }
   
   void remove(Type x,BinaryNode * &t){
       if(t==NULL) return;
       if(x<t->data) remove(x,t->left);
       else if(x>t->data) remove(x,t->right);
       else if(t->left==NULL && t->right==NULL){
           BinaryNode *oldNode=t;
           t=NULL;
           delete oldNode;
       }
       else if(t->left!=NULL){
           t->data=findMax(t->left)->data;
           remove(t->data,t->left);
       }
       else if(t->right!=NULL){
            t->data=findMin(t->right)->data;
            remove(t->data,t->right);
       }  
   }


   BinaryNode *clone(BinaryNode *t){
       if(t==NULL) return NULL;
       return new BinaryNode(t->data,clone(t->left),clone(t->right));
   }   
  
public:
   BinarySearchTree() {root=NULL;}
   BinarySearchTree(const BinarySearchTree *rhs) {root=rhs;}
   ~BinarySearchTree() {makeEmpty();}

   const Type &findMin() const {return findMin(root)->data;}
   const Type &findMax() const {return findMax(root)->data;}
   bool contains(Type x) const {
       if(contains(x,root)==NULL) return false;
       else return true;
   }
   bool isEmpty()  const   {if(root==NULL) return true; else return false;}
   void printTree() const {printTree(root);}

   void makeEmpty()   {makeEmpty(root);}
   void insert(Type x) {insert(x,root);}
   void remove(Type x) {remove(x,root);}

   const BinarySearchTree & operator=(const BinarySearchTree &rhs){
       if(this!=&rhs){
           makeEmpty();
           root=clone(rhs.root);
       }
       return *this;
   }
};
/*
 * 
 */
int main(int argc, char** argv) {

    BinarySearchTree<int>b; 
    int data;
    
    int menu=1;
    cout<<"1：插入    2：删除     3：查找 \n";
    cout<<"4:最大值   5：最小值   6：打印\n";
    cout<<"0:退出";
    while(menu!=0){
        cout<<"选择：";
        cin>>menu;
        if(menu==1) {cin>>data;b.insert(data);}
        if(menu==2) {cin>>data;b.remove(data);}
        if(menu==3) {cin>>data;b.contains(data);}
        if(menu==4) cout<<b.findMax()<<"\n";
        if(menu==5) cout<<b.findMin()<<"\n";
        if(menu==6) b.printTree();
     }
    
    
    return 0;
}

