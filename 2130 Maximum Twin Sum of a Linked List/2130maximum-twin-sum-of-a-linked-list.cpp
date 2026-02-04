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
    int pairSum(struct ListNode* head) {
        struct ListNode* curr = head;
        int cnt = 0, max = 0;
        while (curr != NULL) {
            cnt++;
            curr = curr->next;
        }
        curr = head;
        for (int i = cnt / 2; i > 0; i--) {
            curr = curr->next;
        }
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        for (int i = cnt / 2; i > 0; i--) {
            if (head->val + prev->val > max) {
                max = head->val + prev->val;
            }
            head = head->next;
            prev = prev->next;
        }
        return max;
    }
};