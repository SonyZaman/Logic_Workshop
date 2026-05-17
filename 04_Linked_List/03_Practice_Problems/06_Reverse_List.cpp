//https://leetcode.com/problems/reverse-linked-list/description/?envType=problem-list-v2&envId=linked-list
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
    ListNode* reverseList(ListNode* head) {
        
       if(head == nullptr || head->next == nullptr) return head;
       ListNode* rec_rev_fst_node = reverseList(head->next);
       head->next->next=head;
       head->next = nullptr;

       return rec_rev_fst_node;



    }
};