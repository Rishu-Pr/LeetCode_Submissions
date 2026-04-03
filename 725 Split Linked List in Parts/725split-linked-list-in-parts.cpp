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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }

        int carry = count % k;
        int base_num = count/k;

        vector<ListNode*> Ans;
        while((k--) > 0){
            if(!head){
                Ans.push_back(NULL);
                continue;
            }
            ListNode* start = head;
            int steps = (carry>0) ? base_num + 1 : base_num;
            carry--;

            for(int i = 0; i < steps-1; i++){
                head = head->next;
            }

            temp = head;
            head = head->next;
            temp->next = NULL;

            Ans.push_back(start);
        }

        return Ans;
    }
};