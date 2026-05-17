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
    queue<pair<Node*,int>>que;

    que.push({root,0});

    while(!que.empty()){

        pair<Node*,int> p = que.front();
        Node* currentNode = p.first;
        int level = p.second;
        que.pop();

        cout<<"level: "<<level<<" - value: "<<(*currentNode).val<<", ";

        if((*currentNode).left!=NULL){
            que.push({(*currentNode).left,level+1});
        }

        if((*currentNode).right!=NULL){
            que.push({(*currentNode).right,level+1});
        }
    }
}



int main(){

  

    //bfs(root);

   
}