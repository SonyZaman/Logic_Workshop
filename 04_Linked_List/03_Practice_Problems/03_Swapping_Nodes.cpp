//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/?envType=problem-list-v2&envId=linked-list

#include<bits/stdc++.h>
using namespace std;


 //Definition for singly-linked list.
 //__question part--
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* o_k = head;
        ListNode* n_k = head;
        int sz=0;
        
        while(tmp!=NULL){
             tmp = (*tmp).next;
             sz++;
        }
        cout<<sz<<"\n";
        
        int x=sz-k+1;
        while(k!=1){
             o_k = (*o_k).next;
             k--;
        }
        cout<<(*o_k).val<<"\n";
         while(x!=1){
             n_k = (*n_k).next;
             x--;
        }
        cout<<(*n_k).val<<"\n";
        swap((*o_k).val,(*n_k).val);
        return head;

    }
};