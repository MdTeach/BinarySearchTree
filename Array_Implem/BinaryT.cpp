#include<iostream>
#include "BinaryT.h"

BinaryT::BinaryT(){
    std::cout<<"Tree inited\n";
}

void BinaryT::add(int k){
    int indexToAdd = 1;
    Node* node = new Node(indexToAdd,k);

    if(isEmpty()){
        //Add data to first element of array
        addToIndex(indexToAdd,node);
    }else{
        Node* root = datas[1];
        insert(root, node);
    }
}


bool BinaryT::isEmpty(){
    return (this->datas[1] == NULL);
}

void BinaryT::insert(Node* root, Node* node){
    if(root == NULL){
        *root = *node;
    }else if(root->data > node->data){
        //add to left
        insert(root->left,node);
    }else{
        //add to right
        insert(root->right,node);
    }
}

void BinaryT::traverse(Traverse trav){
    

} 