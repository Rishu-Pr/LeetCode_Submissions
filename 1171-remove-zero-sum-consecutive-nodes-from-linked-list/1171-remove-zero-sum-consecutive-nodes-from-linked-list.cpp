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
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;

        int sum = 0;
        ListNode *h = head;
        while(h){
            sum += h->val;

            if(sum == 0){
                head = h->next;
                return removeZeroSumSublists(head);
            }
            h = h->next;
        }

        head->next = removeZeroSumSublists(head->next);
        return head;
    }
};