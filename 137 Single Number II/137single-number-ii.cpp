class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size();)
        {
            if (i == nums.size() - 1 || i == nums.size() - 2)
                return nums[i];

            sum = (nums[i] & nums[i + 1]) ^ nums[i + 2];
            
            if (sum == 0) i += 3;
            else
                return nums[i];
        }
        return -1;
    }
};