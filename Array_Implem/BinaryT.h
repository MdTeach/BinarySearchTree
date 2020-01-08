#pragma once
#define MAX_SIZE 100

class Node {
public:
  int key;
  Node* left;
  Node* right;
};

enum Traverse {
    PRE_ORDER, 
    IN_ORDER, 
    POST_ORDER
};


class BinaryT{
    public:
    BinaryT();

    //Return the number of nodes in the tree
    int  size();

    //Add data to the binary tree
    void add(int key);

    //Remove the node with Key k.
    void remove(int k);

    //Return the node with Key k. else throw an exception.
    int find(int k);

    //Return true if there is an node with Key k in the table. else return false
    bool keyExists(int k);


    void traverse(Traverse traverse);

    private:
    Node* datas[MAX_SIZE];
};
