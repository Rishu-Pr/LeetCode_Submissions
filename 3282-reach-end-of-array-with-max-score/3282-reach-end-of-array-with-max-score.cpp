class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long sum = 0;
        int idx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[idx]){
                sum += (nums[idx] * 1ll) * (i - idx);
                idx = i;
            }
        }

        if(idx != nums.size() - 1){
            sum += (nums[idx] * 1ll )* (nums.size() - 1 - idx);
        }

        return sum;
    }
};