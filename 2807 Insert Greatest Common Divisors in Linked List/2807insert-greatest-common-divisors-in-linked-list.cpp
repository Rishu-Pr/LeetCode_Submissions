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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        struct ListNode *curr = head;
        while (curr->next != NULL)
        {
            struct ListNode *temp = new struct ListNode;
            temp->val = gcd(curr->val,curr->next->val);

            temp->next = curr->next;
            curr->next = temp;

            curr = temp->next;
        }
        return head;
    }
};