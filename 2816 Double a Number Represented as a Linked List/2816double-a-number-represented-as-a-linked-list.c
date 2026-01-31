/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    struct ListNode *V_Ans = head;
    struct ListNode *prev = NULL;

    while (V_Ans != NULL)
    {
        if (V_Ans->val < 5)
        {
            V_Ans->val *= 2;
        }
        else
        {
            if (V_Ans == head)
            {
                struct ListNode *temp = malloc(sizeof(struct ListNode));
                temp->val = 1;
                temp->next = head;
                head = temp;
            }
            else
            {
                prev->val += 1;
            }
            V_Ans->val = (V_Ans->val * 2) - 10;
        }
        prev = V_Ans;
        V_Ans = V_Ans->next;
    }
    return head;
}