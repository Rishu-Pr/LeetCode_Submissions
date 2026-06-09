class Solution {
    unordered_map <string, int> dp;
    int solve(vector<int>& nums, string& visited, int turn_no){
        if(2 * turn_no > nums.size()) return 0;
        if(dp.count(visited)) return dp[visited];

        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(visited[i] == '0' && visited[j] == '0'){
                    visited[i] = '1';
                    visited[j] = '1';
                    int n1 = nums[i];
                    int n2 = nums[j];

                    ans = max(ans, turn_no * __gcd(n1, n2) + solve(nums, visited, turn_no + 1));
                    visited[i] = '0';
                    visited[j] = '0';
                }
            }
        }

        return dp[visited] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        string visited(nums.size(), '0');
        return solve(nums, visited, 1);
    }
};