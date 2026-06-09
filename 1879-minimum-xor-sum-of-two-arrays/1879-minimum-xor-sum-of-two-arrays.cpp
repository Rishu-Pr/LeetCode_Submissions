class Solution {
    unordered_map <string, int>dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int idx1, string& visited){
        if(idx1 == nums1.size()) return 0;
        if(dp.count(visited)) return dp[visited];

        int ans = INT_MAX;
        for(int i = 0; i < nums2.size(); i++){
            if(visited[i] == '0'){
                visited[i] = '1';
                ans = min(ans, (nums1[idx1] ^ nums2[i]) + solve(nums1, nums2, idx1 + 1, visited));
                visited[i] = '0';
            }
        }

        return dp[visited] = ans;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        string visited(nums2.size(), '0');

        return solve(nums1, nums2, 0, visited);
    }
};