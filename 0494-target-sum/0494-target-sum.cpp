class Solution {
    void solve(vector<int>& nums, int idx, int target, int& count){
        if(idx == nums.size()){
            if(target == 0){
                count++;
            }
            return;
        }

        int num = nums[idx];
        solve(nums, idx + 1, target - num, count);
        solve(nums, idx + 1, target + num, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == 0 && target == 0){
                return 2;
            }
            return (nums[0] == target || nums[0] == -target) ? 1 : 0;
        }
        
        int count = 0;
        solve(nums, 0, target, count);

        return count;
    }
};