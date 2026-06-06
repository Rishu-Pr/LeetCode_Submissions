class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int sum = 0;
        int curr = 0;
        int maxV = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            curr += i * nums[i];
        }
        maxV = curr;

        for(int i = 1; i < nums.size(); i++){ 
            curr = curr + (nums.size() * nums[i - 1]) - sum;
            maxV = max(maxV, curr);
        }
        return maxV;
    }
};