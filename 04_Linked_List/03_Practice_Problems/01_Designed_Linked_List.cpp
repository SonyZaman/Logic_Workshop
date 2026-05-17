//https://leetcode.com/problems/design-linked-list/submissions/1997305785/?envType=problem-list-v2&envId=linked-list
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        (*this).val = val;
        (*this).next = NULL;
    }
};


class MyLinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {
        
    }
    
    int get(int index) {

    Node* tmp = head;

    for(int i = 0; i < index; i++){

        if(tmp == NULL)return -1;

        tmp = (*tmp).next;
    }

    if(tmp == NULL)return -1;

    return (*tmp).val;
}
      
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head==NULL){

              head = newNode;
              tail = newNode;
              return;
        }
        (*newNode).next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
         if(head==NULL){

              head = newNode;
              tail = newNode;
              return;
        }
        //(*tail).next = newNode;
        tail->next = newNode;
        tail = newNode;
    }
    
    void addAtIndex(int index, int val) {

    if(index == 0){
        addAtHead(val);
        return;
    }

    Node* tmp = head;

    for(int i = 0; i < index-1; i++){

        if(tmp == NULL)return;

        tmp = (*tmp).next;
    }

    if(tmp == NULL)return;

    Node* newNode = new Node(val);

    (*newNode).next = (*tmp).next;
    (*tmp).next = newNode;

    if((*newNode).next == NULL){
        tail = newNode;
    }
}
    
void deleteAtHead(){
   
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
 void deleteAtIndex(int index) {

    if(head == NULL)return;

    if(index == 0){
        deleteAtHead();
        return;
    }

    Node* tempCurrentNode = head;

    for(int i = 0; i < index-1; i++){

        if(tempCurrentNode == NULL)return;

        tempCurrentNode = tempCurrentNode->next;
    }

    if(tempCurrentNode == NULL)return;

    if(tempCurrentNode->next == NULL)return;

    Node* deleteNode = tempCurrentNode->next;

    tempCurrentNode->next = tempCurrentNode->next->next;

    if(tempCurrentNode->next == NULL){
        tail = tempCurrentNode;
    }

    delete deleteNode;
}
};