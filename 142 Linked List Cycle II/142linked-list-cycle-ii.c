/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast_Ptr = head;
    struct ListNode *slow_Ptr = head;
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    do
    {
        if (fast_Ptr == NULL || fast_Ptr->next == NULL)
        {
            return NULL;
        }
        fast_Ptr = fast_Ptr->next->next;
        slow_Ptr = slow_Ptr->next;
    } while (fast_Ptr != slow_Ptr);
    fast_Ptr = head;
    while (fast_Ptr != slow_Ptr)
    {
        fast_Ptr = fast_Ptr->next;
        slow_Ptr = slow_Ptr->next;
    }
    return slow_Ptr;
}
