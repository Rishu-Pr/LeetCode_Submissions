/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *prev = NULL;
    struct ListNode *Beforeprev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = head;

    for (int i = 1; i < left; i++)
    {
        Beforeprev = curr;
        curr = curr->next;
    }
    struct ListNode *curr_head = curr;

    for (int i = left; i <= right; i++)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (Beforeprev != NULL)
    {
        Beforeprev->next = prev;
    }
    else
    {
        head = prev;
    }

    curr_head->next = curr;

    return head;
}