//https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=problem-list-v2&envId=linked-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* szTra = head;
        ListNode* tra = head;
        int sz = 0;

        if(head->next==NULL){
            delete head;
            return NULL;
        }


        while(szTra!=NULL){

            szTra=szTra->next;
            sz++;

        }

        if(n==sz){
          
        ListNode* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;

        }
        int x = sz-n;

        for(int i=0;i<x-1;i++){

               tra=tra->next;
        }

        ListNode* deleteNode = tra->next;
       
        tra->next = tra->next->next;
         
        delete deleteNode;
      
        return head;
    }
};