/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *dummy = head;
    int cnt = 0;
    while (dummy != NULL)
    {
        cnt++;
        dummy = dummy->next;
    }
    if (cnt <= 1 || k % cnt == 0)
    {
        return head;
    }

    k = k % cnt;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *newHead;

    for (int i = 0; i < cnt - k; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    newHead = curr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head;

    return newHead;
}