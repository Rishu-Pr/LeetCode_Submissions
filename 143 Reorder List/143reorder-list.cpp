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
    void reorderList(ListNode* head) {
        
        deque<ListNode *> dq;
        ListNode *ittr = head;
        
        while (ittr != NULL){
            dq.push_back(ittr);
            ittr = ittr->next;
        }

        ittr = dq.front();
        dq.pop_front();

        while (!dq.empty()){
            ittr->next = dq.back();
            dq.pop_back();
            ittr = ittr->next;
            
            if (!dq.empty()){
                ittr->next = dq.front();
                dq.pop_front();
                ittr = ittr->next;
            }
        }
        ittr->next = NULL;
    }
};