/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = head;
    struct ListNode *phead = NULL;
    struct ListNode *chead = head;

    int len = 0;
    struct ListNode *dummy = head;

    while (dummy != NULL)
    {
        len++;
        dummy = dummy->next;
    }

    for (int i = 0; i < len / k; i++)
    {
        int count = 0;
        prev = NULL;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (i == 0)
        {
            head = prev;
        }
        else
        {
            phead->next = prev;
        }
        chead->next = curr;
        phead = chead;
        chead = curr;
    }
    return head;
}