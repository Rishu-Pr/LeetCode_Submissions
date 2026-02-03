/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *prev1 = NULL;
    struct ListNode *curr = l1;
    struct ListNode *next = l1;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev1;
        prev1 = curr;
        curr = next;
    }

    struct ListNode *prev2 = NULL;
    curr = l2;
    next = l2;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev2;
        prev2 = curr;
        curr = next;
    }

    struct ListNode *Ans = NULL;
    int carry = 0;

    while (prev1 != NULL || prev2 != NULL || carry)
    {
        int sum = carry;
        if (prev1 != NULL)
        {
            sum += prev1->val;
            prev1 = prev1->next;
        }
        if (prev2 != NULL)
        {
            sum += prev2->val;
            prev2 = prev2->next;
        }
        carry = sum / 10;

        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = Ans;
        Ans = temp;
    }
    return Ans;
}