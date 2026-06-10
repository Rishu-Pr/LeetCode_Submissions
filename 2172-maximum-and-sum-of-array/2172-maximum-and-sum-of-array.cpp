class Solution {
    unordered_map <string, int>dp;
    int solve(vector<int>& nums, int idx, string& visited){
        if(idx == nums.size()) return 0;
        if(dp.count(visited)) return dp[visited];

        int ans = -1e7;
        for(int i = 1; i < visited.size(); i++){
            if(visited[i] < '2'){
                visited[i]++;
                int val = (nums[idx] & i) + solve(nums, idx + 1, visited);
                ans = max(ans, val);
                visited[i]--;
            }
        }

        return dp[visited] = ans;
    }
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        string visited(numSlots + 1, '0');
        return solve(nums, 0, visited);
    }
};