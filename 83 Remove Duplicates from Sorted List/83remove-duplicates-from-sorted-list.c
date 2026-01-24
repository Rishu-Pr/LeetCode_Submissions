/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* ptr = head;
    while (ptr != NULL && ptr->next != NULL) {
        if (ptr->val == ptr->next->val) {
            struct ListNode* dup = ptr->next;
            ptr->next = dup->next;
            free(dup);
        } else {
            ptr = ptr->next;
        }
    }
    return head;
}