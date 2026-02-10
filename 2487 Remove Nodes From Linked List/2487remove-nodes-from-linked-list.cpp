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
    ListNode *reverse(ListNode *head){
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *next = NULL;

        while (curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *removeNodes(ListNode *head){
        struct ListNode *prev = reverse(head);
        int max = prev->val;
        struct ListNode *ittr = prev;

        while (ittr != NULL && ittr->next != NULL){
            if (ittr->next->val < max){
                ittr->next = ittr->next->next;
            }
            else{
                ittr = ittr->next;
                max = ittr->val;
            }
        }
        return reverse(prev);
    }
};