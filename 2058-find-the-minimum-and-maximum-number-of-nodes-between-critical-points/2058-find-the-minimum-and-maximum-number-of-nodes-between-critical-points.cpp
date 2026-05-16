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
        vector<int> h;
        while(head){
            h.push_back(head->val);
            head = head->next;
        }
        vector<int> ans = {-1,-1};
        if(h.size() == 2) return ans;

        vector<int> cp;
        for(int i = 1; i < h.size() - 1; i++){
            if(h[i] < h[i - 1] && h[i] < h[i + 1]) cp.push_back(i);
            else if(h[i] > h[i - 1] && h[i] > h[i + 1]) cp.push_back(i);
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