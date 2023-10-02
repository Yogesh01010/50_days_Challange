/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

    //Base cse
    if(head == NULL){
        return NULL;
    }

    //step 1 reverse first k nodes (means first group)
    ListNode* forward = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;

    int count = 0;

    while(curr != NULL  && count < k){
        forward =  curr->next;
        curr->next  = prev;
        prev = curr;
        curr = forward;
        count++;
    }
        // step 2 recursion dekh lega left groups ko
        if(forward != NULL) {
            head -> next = reverseKGroup(forward,k);
        }

        // step 3
        return prev;
    }
};