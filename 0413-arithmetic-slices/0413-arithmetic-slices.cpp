class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int count = 0;

        int left = 0;
        while(left < nums.size() - 1){
            int right = left + 1;
            int diff = nums[right] - nums[left];

            while((right < nums.size() -1) && (nums[right + 1] == nums[right] + diff)){
                right++;
                if(right - left + 1 >= 3) count++;
            }

            left++;
        }

        return count;
    }
};