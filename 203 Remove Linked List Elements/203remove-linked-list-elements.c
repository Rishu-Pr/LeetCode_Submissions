/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    while (head != NULL && head->val == val)
    {
        struct ListNode *removeHead = head;
        head = head->next;
        free(removeHead);
    }

    struct ListNode *curr = head;
    struct ListNode *prev = NULL;

    while (curr != NULL)
    {
        if (curr->val == val)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}