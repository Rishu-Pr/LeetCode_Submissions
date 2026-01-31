/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *V_Ans = NULL, *tail = NULL;

    while (l1 != NULL || l2 != NULL)
    {
        struct ListNode *V_Temp = malloc(sizeof(struct ListNode));
        if (l1 != NULL && l2 != NULL)
        {
            V_Temp->val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 == NULL)
        {
            V_Temp->val = l2->val + carry;
            l2 = l2->next;
        }
        else
        {
            V_Temp->val = l1->val + carry;
            l1 = l1->next;
        }

        carry = V_Temp->val / 10;
        V_Temp->val = V_Temp->val % 10;

        V_Temp->next = NULL;
        if (V_Ans == NULL)
        {
            V_Ans = V_Temp;
            tail = V_Temp;
        }
        else
        {
            tail->next = V_Temp;
            tail = V_Temp;
        }
    }
    if (carry)
    {
        struct ListNode *V_Temp = malloc(sizeof(struct ListNode));
        V_Temp->val = carry;
        V_Temp->next = NULL;
        tail->next = V_Temp;
        tail = V_Temp;
    }
    return V_Ans;
}