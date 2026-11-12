class Solution {
    double solve(vector<int>& nums, int k, vector<double>& Karr, int idx, int kdx, vector<int>& count, vector<vector<vector<double>>>& dp) {
        if (idx == nums.size()) {
            double sum = 0.0;
            if (count[kdx]) {
                sum += Karr[kdx] / count[kdx];
            }
            return sum;
        }

        int c = count[kdx];
        if (dp[idx][kdx][c] != -1.0) {
            return dp[idx][kdx][c];
        }

        Karr[kdx] += nums[idx];
        count[kdx]++;
        double ans = solve(nums, k, Karr, idx + 1, kdx, count, dp);
        Karr[kdx] -= nums[idx];
        count[kdx]--;

        if (kdx < k - 1 && count[kdx] > 0) {
            double cAvg = Karr[kdx] / count[kdx];
            ans = max(ans, cAvg + solve(nums, k, Karr, idx, kdx + 1, count, dp));
        }

        return dp[idx][kdx][c] = ans;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> Karr(k, 0);
        vector<int> count(k, 0);

        vector<vector<vector<double>>> dp(n, vector<vector<double>>(k, vector<double>(n + 1, -1.0)));
        return solve(nums, k, Karr, 0, 0, count, dp);
    }
};