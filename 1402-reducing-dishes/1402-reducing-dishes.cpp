class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--){

            for(int j = i; j >= 0; j--){
                int inc = satisfaction[i] * (j + 1) + dp[i + 1][j + 1];
                int exc = dp[i + 1][j];
                dp[i][j] = max(inc, exc);
            }
        }

        return dp[0][0];
    }
};