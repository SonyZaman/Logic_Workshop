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

void preorder(Node* root){

    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){

    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void inorder(Node* root){

    if(root == NULL) return;
  
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
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

    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    inorder(root);
}