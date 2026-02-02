struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode newHead;
    newHead.next = head;
    struct ListNode *prev = &newHead;
    struct ListNode *curr = head;

    while (curr != NULL)
    {
        int duplicate = 0;
        while (curr->next != NULL && curr->val == curr->next->val)
        {
            struct ListNode *temp = curr->next;
            curr->next = temp->next;
            free(temp);
            duplicate = 1;
        }
        if (duplicate)
        {
            struct ListNode *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(temp);
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return newHead.next;
}