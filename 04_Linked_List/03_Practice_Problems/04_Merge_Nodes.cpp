//https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=problem-list-v2&envId=linked-list

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* traversal = head;
        ListNode* for_val_in = head;
        int sum = 0;

        while(true){
            traversal = (*traversal).next;
            sum+=(*traversal).val;
            if((*traversal).val == 0 && (*traversal).next!=NULL){
                (*for_val_in).val = sum;
                for_val_in = (*for_val_in).next;
                sum = 0;
            }
            if((*traversal).val == 0 && (*traversal).next==NULL){
                (*for_val_in).val = sum;
                (*for_val_in).next = NULL;
                sum = 0;
                break;
            }
        }
        return head;
    }
    
};