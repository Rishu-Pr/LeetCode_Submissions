class Solution {
    void solve(vector<vector<int>>& Ans, vector<int>& temp, vector<int>& nums, int idx){
        if(temp.size() > 1){
            Ans.push_back(temp);
        }
        unordered_set<int> used;
        for(int i = idx; i < nums.size(); i++){
            if ((temp.empty() || nums[i] >= temp.back()) && used.find(nums[i]) == used.end()) {
            temp.push_back(nums[i]);
            solve(Ans, temp, nums, i + 1);
            temp.pop_back();
            used.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> Ans;
        vector<int> temp;

        solve(Ans, temp, nums, 0);

        return Ans;
    }
};