#include<iostream>
#include "BinaryT.h"

int main(){
    BinaryT bt;

    //Adding the data

    bt.add(10);
    bt.add(0);
    bt.add(12);
    bt.add(14);
    bt.add(2);
    bt.add(7);

    std::cout<<"\nSize is "<<bt.size()<<" \n";
    std::cout<<"Traverse LVR"<<std::endl;
    bt.traverse(LVR);
    std::cout<<std::endl;
    
    std::cout<<"Traverse LRV"<<std::endl;
    bt.traverse(LRV);
    std::cout<<std::endl;

    std::cout<<"Traverse VLR"<<std::endl;
    bt.traverse(VLR);
    std::cout<<std::endl;
    
    std::cout<<"Does 2 exists ?"<<std::endl;
    if(bt.dataExists(2)){
        std::cout<<"Yes\n";
    }else{
        std::cout<<"Nope\n";
    }
    std::cout<<std::endl;

    std::cout<<"Remove 0"<<std::endl;
    bt.remove(0);
    std::cout<<std::endl;

    std::cout<<"Traverse LVR again"<<std::endl;
    bt.traverse(LVR);
    std::cout<<"\nAll done";

    return 0;
}