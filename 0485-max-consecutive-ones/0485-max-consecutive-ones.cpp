class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxV = 0;
        int prev = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                maxV = max(maxV, nums[i] - prev);
                prev = nums[i];
            }
        }
        maxV = max(maxV, nums.back() - prev);

        return maxV;
    }
};