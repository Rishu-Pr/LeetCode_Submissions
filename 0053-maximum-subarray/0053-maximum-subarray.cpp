class Solution {
    int maxCross(vector<int>& nums, int l, int r, int mid){
        int lSum = INT_MIN;
        int rSum = INT_MIN;
        int sumL = 0;
        int sumR = 0;

        for(int i = mid; i >= l; i--){
            sumL += nums[i];
            if(sumL > lSum){
                lSum = sumL;
            }
        }

        for(int i = mid + 1; i <= r; i++){
            sumR += nums[i];
            if(sumR > rSum){
                rSum = sumR;
            }
        }

        return lSum + rSum;
    }
    int maxSum(vector<int>& nums, int l, int r){
        if(l == r){
            return nums[l];
        }
        int m = (r + l) / 2;
        int maxS = max(maxCross(nums, l, r, m), max(maxSum(nums, l, m), maxSum(nums, m + 1, r)));

        return maxS;
    }
public:
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1);
    }
};