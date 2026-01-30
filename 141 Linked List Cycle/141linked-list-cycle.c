/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slowptr = head;
    struct ListNode *fastptr = head;

    do{
        if(fastptr == NULL || fastptr->next == NULL){
            return false;
        }
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }while(slowptr != fastptr);

    return true;
}