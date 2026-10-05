class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());

        long long val = 0;
        int s = 0;
        int e = nums.size() - 1;

        for(int i = 0; i < nums.size() / 2; i++){
            val -= nums[i];
        }
        for(int i = nums.size() / 2; i < nums.size(); i++){
            val += nums[i];
        }

        return val;
    }
};