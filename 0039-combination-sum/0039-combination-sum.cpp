class Solution {
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            int val = candidates[i];
            if(target - val >= 0){
                temp.push_back(val);
                solve(candidates, target - val, ans, temp, i);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, ans, temp, 0);
        return ans;
    }
};