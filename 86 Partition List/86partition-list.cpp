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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL) return NULL;
        struct ListNode *next = head;
        struct ListNode *h1 = NULL; // smaller
        struct ListNode *t1 = NULL; // smaller

        struct ListNode *h2 = NULL; // greater
        struct ListNode *t2 = NULL; // greater
        while (head != NULL)
        {
            next = head->next;
            head->next = NULL;
            if (head->val < x){
                if (h1 == NULL)
                {
                    h1 = head;
                    t1 = head;
                }
                else
                {
                    t1->next = head;
                    t1 = head;
                }
            }
            else{
                if (h2 == NULL)
                {
                    h2 = head;
                    t2 = head;
                }
                else
                {
                    t2->next = head;
                    t2 = head;
                }
            }
            head = next;
        }
        if (t1 == NULL) return h2;

        t1->next = h2;
        return h1;
    }
};