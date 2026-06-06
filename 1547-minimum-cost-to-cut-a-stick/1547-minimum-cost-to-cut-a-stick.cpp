class Solution {
    int solve(int start_idx, int end_idx, vector<int>& cuts, vector<vector<int>>& dp){
        if(end_idx - start_idx == 1) return 0;
        if(dp[end_idx][start_idx] != -1) return dp[end_idx][start_idx];

        int cost = INT_MAX;
        
        for(int i = start_idx + 1; i < end_idx; i++){
            int length = cuts[end_idx] - cuts[start_idx];
            cost = min(length + solve(start_idx, i, cuts, dp) + solve(i, end_idx, cuts, dp), cost);    
        }

        return dp[end_idx][start_idx] = cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));

        return solve(0, size - 1, cuts, dp);
    }
};