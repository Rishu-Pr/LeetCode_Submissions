/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = head;

    struct ListNode *cHead = head;
    struct ListNode *pHead = NULL;

    int len = 0;
    struct ListNode *dummy = head;
    while(dummy != NULL){
        len++;
        dummy = dummy->next;
    }

    for(int i = 0; i < len/2 ;i++){
        prev = NULL;
        int count = 0;

        while(curr != NULL && count<2){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(i == 0){
            head = prev;
        }
        else{
            pHead->next = prev;
        }
        cHead->next = curr;
        pHead = cHead;
        cHead = curr;
    }
    return head;
}