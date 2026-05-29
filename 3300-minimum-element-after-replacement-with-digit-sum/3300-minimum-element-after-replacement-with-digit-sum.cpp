class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int digit_sum = 0;
            while(nums[i] > 0){
                digit_sum += nums[i] % 10;
                nums[i] /= 10;
            }

            nums[i] = digit_sum;
        }

        int minVal = nums[0];
        for(int i = 1; i < nums.size(); i++)
            minVal = min(minVal, nums[i]);

        return minVal;
    }
};