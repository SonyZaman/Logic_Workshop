//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/?envType=problem-list-v2&envId=linked-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        if(temp==NULL||temp->next==NULL)return head;
        while(temp!=NULL && temp->next!=NULL){

            
            if(temp->val==temp->next->val){
                ListNode* deleteNode = temp->next;
                temp->next = temp->next->next;
                delete deleteNode;
            }else
            temp=temp->next;
        }

        return head;
    }
};