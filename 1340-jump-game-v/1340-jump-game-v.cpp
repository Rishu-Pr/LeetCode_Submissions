class Solution {
    int solve(vector<int>& arr, int d, int idx, vector<int>& dp){
        if(idx >= arr.size() || idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int maxSteps = 1;
        for(int i = idx + 1; i <= min((int)arr.size() - 1, idx + d); i++){
            if(arr[i] >= arr[idx]) break;
            maxSteps = max(maxSteps, 1 + solve(arr, d, i, dp));
        }
        for(int i = idx - 1; i >= max(0, idx - d); i--){
            if(arr[i] >= arr[idx]) break;
            maxSteps = max(maxSteps, 1 + solve(arr, d, i, dp));
        }

        dp[idx] = maxSteps;
        return dp[idx];
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;

        for(int i = 0; i < arr.size(); i++) ans = max(ans, solve(arr, d, i, dp));
        return ans;
    }
};