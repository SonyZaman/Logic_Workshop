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

// Node* &head -->> head is a reference to a pointer to Node
void insertAtTail(Node* &head, Node* &tail, int val) {

    // newNode is not a Node object itself; it is a pointer that points or stores the address of a Node object created in heap memory.
    Node* newNode = new Node(val);

    // Check if the linked list is empty
    if (head == NULL) {

        // head = newNode; means the pointer head now stores the same address that newNode stores (i.e., both point to the same Node object).
        head = newNode;

        // tail = newNode; means the pointer tail now stores the same address that newNode stores.
        tail = newNode;

        // Exit the function because insertion is done
        return;
    }

    // (*tail).next = newNode; tail stores the address of a node. After dereferencing it (using -> , *), we access that node’s members (val, next). The next pointer of that node stores the address of newNode, so the current last node is now connected to the new node
    tail->next = newNode;

    // tail = newNode; means the pointer tail now stores the same address that newNode stores.
    // tail = tail->next;
    tail = newNode;
}



void printList(Node* &head, Node* &tail){
      
      Node* tmp ;
      tmp = head;
    
    // will not print last value--> need to fixed edge case
    //   while((*tmp).next!=NULL){
    //      cout<<(*tmp).val<<" ";
    //      tmp = (*tmp).next;
    //   }

    //  while(true){
    //      cout<<(*tmp).val<<" ";
    //      if((*tmp).next==NULL) break;
    //      tmp = (*tmp).next;
    // }

    while(tmp!=NULL){
        cout<<(*tmp).val<<" ";
        tmp = (*tmp).next;
    }

}
int main(){

    int n;
    Node* head = NULL;
    Node* tail = NULL;

    // take input
    while(cin >> n){
       // insertAtTail(head, tail, n);
       insertAtTail(head,tail,n);
    }


    printList(head,tail);

    return 0;
}