#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){

        (*this).val = val;
        //this->val=val;
        next=NULL;
    }
};

int main(){
    
    
    Node* newNode = new Node(50); //newNode is not a Node object itself; it is a pointer that stores the address of a Node object created in heap memory.
    cout<<(*newNode).val<<"\n";
    cout<<newNode->val<<"\n";
}