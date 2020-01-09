//Implementation with first element empty

#pragma once
#define MAX_SIZE 1000


class Node {
public:
  int key;
  int data;

  Node(){}
};

enum Traverse {
  LVR,
  LRV,
  VLR,
};


class BinaryT{
    public:
    BinaryT();

    //Return the number of nodes in the tree
    int  size();

    //Add data to the binary tree
    void add(int data);

    //Remove the node with given data.
    void remove(int data);

    //Returns the node's key with given data. else throw an exception.
    int find(int data);

    //Return true if there is an node with data in the table. else return false
    bool dataExists(int k);


    //Print all node's data in the tree
    void traverse(Traverse traverse);

    //check if tree is empty
    bool isEmpty();

    private:
    Node* datas[MAX_SIZE];

    //Add the node to the given index of our array
    void addToIndex(int index, Node* node);

    //travers the given node
    void traverseLVR(Node* root);
    void traverseVLR(Node* root);
    void traverseLRV(Node* root);

    //Add to Right of the given node
    void insert(Node* root, Node* node, int key);

    //Retunr the no of node form the given root node
    int  size(Node* root);

    //returns the index of its right child
    int getRightChildIndex(int key);

    //returns the index of its left child
    int getLeftChildIndex(int key);

    //search in each node
    bool findInNode(Node* root, int data);
    int findRootInNode(Node* root,int data);

    //for removing the node shift the data from lower node to highter
    void shiftChildToRoot(Node* root);

};
