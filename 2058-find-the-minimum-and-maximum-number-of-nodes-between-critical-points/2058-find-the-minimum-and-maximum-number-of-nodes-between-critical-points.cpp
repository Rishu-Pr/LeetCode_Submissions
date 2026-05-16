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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(!head->next->next) return ans;

        vector<int> cp;
        ListNode* prev = head;
        head = head->next;
        int i = 1;
        while(head && head->next){
            if(head->val > prev->val && head->val > head->next->val) cp.push_back(i);
            else if(head->val < prev->val && head->val < head->next->val) cp.push_back(i);

            i++;
            prev = head;
            head = head->next;
        }

        if(cp.size() < 2) return ans;

        ans[1] = cp.back() - cp[0];
        int minV = ans[1];
        for(int i = 0; i < cp.size() - 1; i++)
            minV = min(minV, cp[i + 1] - cp[i]);
        
        ans[0] = minV;

        return ans;
    }
};