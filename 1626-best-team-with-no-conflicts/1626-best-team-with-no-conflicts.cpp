class Solution {
public:
    int solve(vector<vector<int>>& data, int idx, int prev, vector<vector<int>>& dp){
        if(idx < 0){
            return 0;
        }
        if(dp[idx][prev] != -1){
            return dp[idx][prev];
        }

        int take = 0;
        int skip = solve(data, idx - 1, prev, dp);
        if(prev == data.size() || (data[prev][0] >= data[idx][0] && data[prev][1] >= data[idx][1])){
            take = data[idx][1] + solve(data, idx - 1, idx, dp);
        }

        return dp[idx][prev] = max(take, skip);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<vector<int>> data(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            data[i][0] = ages[i];
            data[i][1] = scores[i];
        }
        
        sort(data.begin(), data.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = solve(data, n - 1, n, dp);
        return ans;
    }
};