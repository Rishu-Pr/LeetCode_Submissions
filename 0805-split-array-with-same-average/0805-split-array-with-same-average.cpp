class Solution {
    vector<vector<vector<char>>> memo;

    bool solve(vector<int>& nums, int total_sum, int idx, int Asize, int A) {
        if (idx == nums.size()) {
            int Bsize = nums.size() - Asize;
            
            if (Asize == 0 || Bsize == 0) {
                return false;
            }
            
            int B = total_sum - A;
            return (A * Bsize == B * Asize);
        }

        if (memo[idx][Asize][A] != -1) {
            return memo[idx][Asize][A];
        }

        bool ans1 = solve(nums, total_sum, idx + 1, Asize + 1, A + nums[idx]);
        if (ans1) return memo[idx][Asize][A] = 1;

        bool ans2 = solve(nums, total_sum, idx + 1, Asize, A);
        
        return memo[idx][Asize][A] = ans2;
    }

public:
    bool splitArraySameAverage(vector<int>& nums) {
        int total_sum = 0;
        for(int x : nums){
            total_sum += x;
        }
        
        int n = nums.size();
        memo.assign(n + 1, vector<vector<char>>(n + 1, vector<char>(total_sum + 1, -1)));
        
        return solve(nums, total_sum, 0, 0, 0);
    }
};