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

void insertAtHead(Node* &head,Node* &tail, int val){

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
    
    // First, the new node next  must be linked to the previous first node (which head points to); otherwise, previous first node address will lose track.
    (*newNode).next = head;

    // Now, head points to the address that the new node points to
    head = newNode;

}

void insertAtIndex(Node* &head,Node* &tail,int val, int idx){

    if(idx == 0){

        insertAtHead(head,tail,val);
        return;
    }
    

    // create a temporary Node pointer that stores node addresses while traversing the list
    Node* tempCurrentNode;
    tempCurrentNode = head;


    for(int i = 0;i < idx-1; i++){
        tempCurrentNode=(*tempCurrentNode).next;
    }
    Node* newNode = new Node(val);
    (*newNode).next = (*tempCurrentNode).next;
    (*tempCurrentNode).next = newNode;
    

}

void deleteAtHead(Node* &head,Node* &tail){
   
   if(head==NULL)return;

   if((*head).next==NULL){
    Node *deleteNode = head;
    head = NULL;
    tail = NULL;
    delete deleteNode;
    return;
   } 

   Node *deleteNode = head;
   head=(*head).next;
   delete deleteNode;


}

void deleteAtAny(Node* &head,Node* &tail,int idx){

   if(head==NULL)return;

   if((*head).next==NULL){
    Node *deleteNode = head;
    head = NULL;
    tail = NULL;
    delete deleteNode;
    return;
   } 

    
    Node* tempCurrentNode;
    tempCurrentNode = head;

    for(int i = 0;i < idx-1; i++){
        tempCurrentNode=(*tempCurrentNode).next;
    }

    Node* deleteNode;

    deleteNode = (*tempCurrentNode).next;
    (*tempCurrentNode).next = (*(*tempCurrentNode).next).next; 
    delete deleteNode;


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

    insertAtIndex(head,tail,500,2);

    printList(head,tail);

    cout<<"\n";

    deleteAtHead(head,tail);

    printList(head,tail);

    deleteAtAny(head,tail,1);

    cout<<"\n";

    printList(head,tail);

    return 0;
}