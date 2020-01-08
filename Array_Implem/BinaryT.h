#pragma once
#define MAX_SIZE 100

class Node {
public:
  int key;
  int data;
  Node* left;
  Node* right;

  Node(int key, int data):key(key),data(data){}
  Node(){}
};

enum Traverse {
    PRE_ORDER, //LTR 
    IN_ORDER,  //TLR
    POST_ORDER //LRT
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

    //Return the node with given data. else throw an exception.
    int find(int data);

    //Return true if there is an node with data in the table. else return false
    bool dataExists(int k);


    //Print all node's data in the tree
    void traverse(Traverse traverse);

    //check if tree is empty
    bool isEmpty();

    private:
    Node* root;
    Node* datas[MAX_SIZE];

    //Add the node to the given index of our array
    void addToIndex(int index, Node* node);

    //Add to Right of the given node
    void insert(Node* root, Node* node);

};
