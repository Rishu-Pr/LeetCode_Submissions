/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *V_Ans_head = NULL;
    struct ListNode *V_Ans_tail = NULL;

    while (list1 != NULL || list2 != NULL)
    {
        struct ListNode *temp = malloc(sizeof(struct ListNode));

        if (list1 == NULL)
        {
            temp->val = list2->val;
            list2 = list2->next;
        }
        else if (list2 == NULL)
        {
            temp->val = list1->val;
            list1 = list1->next;
        }
        else if (list1->val > list2->val)
        {
            temp->val = list2->val;
            list2 = list2->next;
        }
        else
        {
            temp->val = list1->val;
            list1 = list1->next;
        }
        temp->next = NULL;

        if (V_Ans_head == NULL)
        {
            V_Ans_head = temp;
            V_Ans_tail = temp;
        }
        else
        {
            V_Ans_tail->next = temp;
            V_Ans_tail = temp;
        }
    }
    return V_Ans_head;
}