#include<iostream>
#include "BinaryT.h"

BinaryT::BinaryT(){
    std::cout<<"Tree inited\n";
}

void BinaryT::add(int data){
    int indexToAdd = 1;
    Node* node = new Node();
    node->data = data;
    node->key = indexToAdd;

    if(isEmpty()){
        //Add data to first element of array
        addToIndex(indexToAdd,node);
    }else{
        Node* root = datas[1];
        insert(root, node, root->key);
    }

}


bool BinaryT::isEmpty(){
    return (this->datas[1] == NULL);
}

void BinaryT::insert(Node* root, Node* node, int key){
    if(root == NULL){
        node->key = key;
        datas[key] = node;
    }else if(root->data > node->data){
        //add to left
        int leftKey = getLeftChildIndex(root->key);
        Node* left = datas[leftKey];
        insert(left,node,leftKey);
    }else{
        //add to right
        int rightKey = getRightChildIndex(root->key);
        Node* right = datas[rightKey];
        insert(right,node,rightKey);
    }
}

//Public
void BinaryT::traverse(Traverse trav){
    if(isEmpty()) throw "Tree is empty";
    Node* root = datas[1];
    if(trav == LVR){
        traverseLVR(root);
    }else if(trav == VLR){
        traverseVLR(root);
    }else if(trav == LRV){
        traverseLRV(root);
    }
} 

//LVR
void BinaryT::traverseLVR(Node* root){
    if(root != NULL){
        
        Node* left = datas[getLeftChildIndex(root->key)];
        traverseLVR(left);
        
        std::cout << root->data <<std::endl;

        Node* right = datas[getRightChildIndex(root->key)];
        traverseLVR(right);
    } 
}

//VLR
void BinaryT::traverseVLR(Node* root){
    if(root != NULL){
        std::cout << root->data <<std::endl;
        
        Node* left = datas[getLeftChildIndex(root->key)];
        traverseVLR(left);
        
        Node* right = datas[getRightChildIndex(root->key)];
        traverseVLR(right);
    } 
}

//LRV
void BinaryT::traverseLRV(Node* root){
    if(root != NULL){
        
        Node* left = datas[getLeftChildIndex(root->key)];
        traverseLRV(left);
        
        Node* right = datas[getRightChildIndex(root->key)];
        traverseLRV(right);

        std::cout << root->data <<std::endl;
    } 
}
        
void BinaryT::addToIndex(int indexToAdd,Node* node){
    datas[indexToAdd] = node;
}


//Public
int BinaryT::size(){
    if(isEmpty()) return 0;
    Node* root = datas[1];
    return size(root); 
}

//Private:
int BinaryT::size(Node* root){
    if(root == NULL) return 0;
    Node* left = datas[getLeftChildIndex(root->key)];
    Node* right = datas[getRightChildIndex(root->key)];
    return size(left) + size(right) + 1; 
}


int BinaryT::getRightChildIndex(int key){
    return 2*key;
}

int BinaryT::getLeftChildIndex(int key){
    return 2*key + 1;
}


//Searching 
bool BinaryT::dataExists(int data){
    if(isEmpty()) return false;
    Node* root = datas[1];
    return findInNode(root, data);
}

bool BinaryT::findInNode(Node* root, int data){
    if(root == NULL)return false;
    if(root->data == data)return true;
    if(root->data > data){
        Node* left = datas[getLeftChildIndex(root->key)];
        return findInNode(left,data);
    }else{
        Node* right = datas[getRightChildIndex(root->key)];
        return findInNode(right,data);
    }
}

int BinaryT::find(int data){
    if(isEmpty()) return 0;
    Node* root = datas[1];
    return findRootInNode(root, data);
}

int BinaryT::findRootInNode(Node* root,int data){
    if(root == NULL)return 0;
    if(root->data == data)return root->key;
    if(root->data > data){
        Node* left = datas[getLeftChildIndex(root->key)];
        return findRootInNode(left,data);
    }else{
        Node* right = datas[getRightChildIndex(root->key)];
        return findRootInNode(right,data);
    }
}

//remvoving part
void BinaryT::remove(int data){
    int keyToBeRemoved = find(data);
    if(keyToBeRemoved == 0){
        std::cout<<"Data not found";
    }else{
        
        Node* nodeToRemove = datas[keyToBeRemoved];
        Node* left = datas[getLeftChildIndex(nodeToRemove->key)];
        Node* right = datas[getRightChildIndex(nodeToRemove->key)];
        if(left == NULL && right == NULL){
            //Its a leaf so just delete
            delete nodeToRemove;
        }else{
            //TODO:
        }
    }
}