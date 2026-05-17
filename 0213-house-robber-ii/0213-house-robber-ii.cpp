class Solution {
    int solve(vector<int>& nums, int s, int e){
        int n = nums.size();

        int prev1 = nums[s];
        int prev2 = max(nums[s], nums[s + 1]);

        for(int i = s + 2; i <= e; i++){
            int inc = prev1 + nums[i];
            int exc = prev2;

            int curr = max(inc, exc);
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int ans1 = solve(nums, 0, n - 2);
        int ans2 = solve(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};