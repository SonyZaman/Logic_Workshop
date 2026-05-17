//https://leetcode.com/problems/linked-list-cycle/description/?envType=problem-list-v2&envId=linked-list
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
    bool hasCycle(ListNode *head) {
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        while(true){


            if(pointer1 == NULL){
                return false;
            }
            else if(pointer1->next==NULL){
              
                return false;
            }  else if(pointer1->next->next==NULL){return false;}
            pointer1 = pointer1->next->next;
            pointer2 = pointer2->next;
            if(pointer1==pointer2){
                return true;
            }
        }
    }
};