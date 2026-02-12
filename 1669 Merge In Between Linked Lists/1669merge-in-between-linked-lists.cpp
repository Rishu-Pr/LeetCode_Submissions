/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *l1_s = list1;
        ListNode *l2_s = list2;

        for (int i = 1; i < a; i++)
            l1_s = l1_s->next;
        
        ListNode *l1_e = l1_s->next;
        l1_s->next = l2_s;

        for (int i = 0; i <= b - a; i++)
            l1_e = l1_e->next;

        while (l2_s->next != NULL)
            l2_s = l2_s->next;
            
        l2_s->next = l1_e;

        return list1;
    }
};