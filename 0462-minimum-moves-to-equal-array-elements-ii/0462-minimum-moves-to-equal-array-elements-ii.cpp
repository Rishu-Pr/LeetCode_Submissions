class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int middle_elem = nums[n / 2];

        int sum = 0;
        for(int curr_elem : nums){
            sum += abs(middle_elem - curr_elem);
        }

        return sum;
    }
};