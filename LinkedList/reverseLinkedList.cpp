/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

leetcode 206; 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL:


        if(head == NULL || head->next == NULL){
          return head;
        }

        while(curr != NULL){
          forward = curr->next;
          current->next = prev;
          prev = curr;
          curr = forward;
        }
        return prev
    }
};


/*

step1->for NULL case = agar head null ho ya head ka next NULL ho to us case me direct heaqd ko return kra do.
step2-> new pointer previous jo NULL ko point kr rha 
        current head pe kr do 
        cueernt k next ko forward me save kra do 
           
step2-> jab tk current ka nex NULL na ho tab tk step 3 chalao 
step 3-> current k next ko previous pe ke do 
         previous ko current pe le jao or current ko forward pe le jao.

step 4 -> prevousko return kkra do .
*/