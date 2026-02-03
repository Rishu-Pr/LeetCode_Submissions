/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeNodes(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = curr->next;

    while (curr != NULL && next != NULL)
    {
        if (curr->val == 0 && prev == NULL)
        {
            head = next;
            free(curr);
            curr = next;
            next = next->next;
        }
        else if (curr->val == 0 && prev != NULL)
        {
            prev->next = next;
            free(curr);
            curr = next;
            next = next->next;
        }
        else if (next->val == 0)
        {
            prev = curr;
            curr = next;
            next = next->next;
        }
        else
        {
            curr->val += next->val;
            curr->next = next->next;
            free(next);
            next = curr->next;
        }
    }
    prev->next = NULL;
    free(curr);
    return head;
}