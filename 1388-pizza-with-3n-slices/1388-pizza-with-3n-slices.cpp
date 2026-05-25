class Solution {
    int solve(vector<int>& slices, int start, int end, int slices_remains, vector<vector<int>>& dp){
        if(slices_remains == 0 || start > end) return 0;
        if(dp[start][slices_remains] != -1) return dp[start][slices_remains];

        int take = slices[start] + solve(slices, start + 2, end, slices_remains - 1, dp);
        int notTake = solve(slices, start + 1, end, slices_remains, dp);

        return dp[start][slices_remains] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        vector<vector<int>> dp1(size + 1, vector<int>(size + 1, -1));
        vector<vector<int>> dp2(size + 1, vector<int>(size + 1, -1));
        
        int firstSlice_inc = solve(slices, 0, size - 2, size / 3, dp1);
        int firstSlice_exc = solve(slices, 1, size - 1, size / 3, dp2);

        return max(firstSlice_inc, firstSlice_exc);
    }
};