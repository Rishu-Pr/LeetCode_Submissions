class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> stk;
        vector<int> ans;
        for(int i = heights.size() - 1; i >= 0 ; i--){
            int x = heights[i];
            int visible = 0;

            while(!stk.empty() && x > stk.top()){
                visible++;
                stk.pop();
            }
            if(!stk.empty()) visible++;

            stk.push(x);
            ans.push_back(visible);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};