#include<bits/stdc++.h>
using namespace std;

//stack-->>push,pop,top,size,empty

class Node{
    public:
      int val;
      Node* next;
      Node* prev;
    
    Node(int val){
        (*this).val=val;
        (*this).next=NULL;
        (*this).prev=NULL;
    }
};

class LinkedList{
    public:
      Node* head = NULL;
      Node* tail = NULL;

    void insertAtTail(int val){

        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        (*tail).next = newNode;
        (*newNode).prev = tail;
        tail = newNode;
    }

    void deleteAtTail(){

        if(head == NULL){
            return;
        }
        if((*head).next == NULL){
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* deleteNode = tail;
        tail = (*tail).prev ;
        (*tail).next = NULL;
        delete deleteNode;   
    }

    void print(){
        
        Node* tmp = head;
        while(tmp!=NULL){
            cout<<(*tmp).val<<" ";
            tmp = (*tmp).next;
        }
        cout<<"\n";
    }

    void reversePrint(){
        
        Node* tmp = tail;
        while(tmp!=NULL){
            cout<<(*tmp).val<<" ";
            tmp = (*tmp).prev;
        }
        cout<<"\n";
    }
};

class MyStack{
    private:
      LinkedList list;
      int sz = 0;
    public:
      void push(int val){

        list.insertAtTail(val);
        sz++;
      }
      void pop(){

        list.deleteAtTail();
        if(sz)sz--;
      }
      int top(){
        return list.tail->val;
      }
      int size(){
        return sz;
      }
      bool empty(){
        return list.head == NULL;
      }



};

int main(){

   MyStack st;
   st.push(5);
   st.push(10);

   st.pop();
   st.pop();
   st.pop();
   
   if(!st.empty())cout<<st.top();

   st.push(15);
   st.push(20);
   st.push(25);
   st.push(30);

   if(!st.empty())cout<<st.top();
}   