class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int min = nums[0];
        for(int x : nums){
            if(x < min){
                min = x;
            }
            sum += x;
        }

        return sum - (min * nums.size());
    }
};