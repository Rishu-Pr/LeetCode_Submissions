class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int minV = nums[i];
            int maxV = nums[i];
            for(int j = i + 1; j < n; j++){
                minV = min(minV, nums[j]);
                maxV = max(maxV, nums[j]);
                sum += maxV - minV;
            }
        }

        return sum;
    }
};