class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums.size(); i++) sum1 += nums[i];

        sum2 = sum1;

        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            rightSum[i] = sum1 - nums[i];
            sum1 -= nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            leftSum[i] = sum2 - nums[i];
            sum2 -= nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            rightSum[i] = abs(leftSum[i] - rightSum[i]);
        }

        return rightSum;
    }
};