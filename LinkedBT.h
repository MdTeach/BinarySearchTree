#include "BinaryTree.h"
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data=0;
        left=right=NULL;
    }
    friend class LinkedBST;
};



class LinkedBST:public BinarySearchTree{
    public:
    Node* root;
    LinkedBST();
    ~LinkedBST();
    void preorderTraversal();
    void preorderTraversal(Node* root);
    void add(int data);
    void add(Node* &root,int data);
    bool search(int data);
    bool search(Node* &root,int targetKey);
    void add(Node* &subtree, Node* newNode);
};


LinkedBST::LinkedBST(){
    root=NULL;
}

LinkedBST::~LinkedBST(){}

void LinkedBST::add(int data){
    add(root,data);
}

void LinkedBST::preorderTraversal(){}

bool LinkedBST::search(int data){}


void LinkedBST::add(Node* &root,int data){
    Node* newNode=new Node();
    newNode->data=data;
    if(root==NULL){
        root=new Node();
        this->root=newNode;
    }
    else{
        add(root,newNode);
    }
}

void LinkedBST::add(Node* &subtree, Node* newNode){
    if(subtree->data>newNode->data){
        if(subtree->left!=NULL){
            add(subtree->left,newNode);
        }
        else{
            subtree->left=newNode;
        }
    }
    else{
        if(subtree->right!=NULL){
            add(subtree->right,newNode);
        }
        else{
            subtree->right=newNode;
        }
    }   
}

bool LinkedBST::search(Node* &root,int targetKey){
    if(root==NULL){
        std::cout<<"It is a Null tree"<<std::endl;
    }
    else{
        Node* p=new Node();
        p=root;
        while(p!=NULL){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}


void LinkedBST::preorderTraversal(Node* root) { 
    if (root == NULL) 
    return; 
  
    
    std::cout << root->data << " "; 
  
    
    preorderTraversal(root->left);  
  
    
    preorderTraversal(root->right); 
}   


