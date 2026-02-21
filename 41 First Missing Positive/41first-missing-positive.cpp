class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int min = 1;
        
        while (nums[i] <= 0) {
            i++;
            if (i >= nums.size()) {
                return 1;
            }
        }

        while (i < nums.size()) {
            if (nums[i] == min) {
                min += 1;
                while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            } else
                return min;
            i++;
        }

        return nums[nums.size() - 1] + 1;
    }
};