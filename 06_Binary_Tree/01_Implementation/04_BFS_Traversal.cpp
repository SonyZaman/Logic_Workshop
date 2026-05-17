#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
      int val;
      Node* right;
      Node* left;

      Node(int val){
         (*this).val=val;
         (*this).right = NULL;
         (*this).left = NULL;
      }
};


void bfs(Node* root){

    if(root==NULL)return;
    queue<Node*>que;

    // First, insert one node so that the while condition
    // does not become false at the beginning
    que.push(root);

    while(!que.empty()){

       // Take the front node from the queue and print its value.
       // Then insert its children into the queue.
       // The children will be added at the end of the queue.
       // The front of the queue may contain its sibling nodes,
        Node* cur = que.front();
        que.pop();

        cout<<(*cur).val<<" ";

        if(cur->left!=NULL){
            que.push(cur->left);
        }

        if(cur->right!=NULL){
            que.push(cur->right);
        }
    }
}


int main(){

    Node* root = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);

    root->left = two;
    root->right = three;
    
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    
    two->left = four;
    two->right = five;

    three->left = six;

    bfs(root);

   
}