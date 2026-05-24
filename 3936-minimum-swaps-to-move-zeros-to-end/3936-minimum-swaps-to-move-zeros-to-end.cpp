class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        int cnt = 0;

        while(start < end){
            while(start < end && nums[start] != 0) start++;
            while(start < end && nums[end] == 0) end--;

            if(start < end){
                swap(nums[start++], nums[end--]);
                cnt++;
            }
        }

        return cnt;
    }
};