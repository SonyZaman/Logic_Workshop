//https://leetcode.com/problems/delete-node-in-a-linked-list/description/?envType=problem-list-v2&envId=linked-list
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
    void deleteNode(ListNode* node) {
        ListNode* next_node = (*node).next;
        (*node).val=(*next_node).val;
        (*node).next=(*next_node).next;
        delete next_node;
   
    }
};