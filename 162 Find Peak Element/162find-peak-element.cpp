class Solution {
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[max] < nums[i])
            {
                max = i;
            }
        }
        return max;
    }
};