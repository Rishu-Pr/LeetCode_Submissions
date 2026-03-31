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

void reverseLL(ListNode * &head,ListNode *curr,ListNode *prev){
    if(!curr){
        head = prev;
        return;
    }
    ListNode *next = curr->next;
    reverseLL(head,next,curr);
    curr->next = prev;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        reverseLL(head,curr,prev);
        return head;
    }
};