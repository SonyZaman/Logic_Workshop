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

void dfs(Node* root){

    if(root == NULL) return;
    cout<<root->val<<" ";
    dfs(root->left);
    dfs(root->right);
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

    dfs(root);

}