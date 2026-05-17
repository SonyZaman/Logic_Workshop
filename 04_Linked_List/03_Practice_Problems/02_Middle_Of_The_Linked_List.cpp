//https://leetcode.com/problems/middle-of-the-linked-list/?envType=problem-list-v2&envId=linked-list
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

  //---
 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        while(true){

             
            if(temp2->next==NULL) {temp2=temp2->next;}
            else {temp2=temp2->next->next;temp1=(*temp1).next;}
           
            if(temp2==NULL)break;
            
        }
        return temp1;

    }
};