#include<iostream>
#include "BinaryT.h"

int main(){
    BinaryT bt;

    //std::cout<<"Size is "<<bt.size()<<" \n";

    bt.add(10);
    std::cout<<"Size is "<<bt.size()<<" \n";

    if(bt.isEmpty()){std::cout<<"EMpts";}else{std::cout<<"Fine\n";}
    
    bt.add(0);
    bt.add(12);
    bt.add(14);
    bt.add(2);
    bt.add(7);

    bt.traverse(LVR);
    std::cout<<"\n\n";
    
    bt.traverse(LRV);
    std::cout<<"\n\n";

    bt.traverse(VLR);
    std::cout<<"\n";

    if(bt.dataExists(2)){
        std::cout<<"Yes\n";
    }else{
        std::cout<<"Nope\n";
    }

    bt.remove(0);

    return 0;
}