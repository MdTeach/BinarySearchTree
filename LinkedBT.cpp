#include<iostream>
#include"LinkedBT.h"
int main(){
    LinkedBST tree;
    tree.add(1);
    tree.add(tree.root,2);
    Node* newNode=new Node();
    newNode->data=3;
    tree.add(tree.root,newNode);
    tree.preorderTraversal(tree.root);
    std::cout<<std::endl<<tree.search(tree.root,2)<<std::endl;
}
