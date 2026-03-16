class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        int x = nums.size();
        while (x > 1)
        {
            int i = 0;
            while (i < x - 1)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
                i++;
            }
            x--;
        }
        return nums[0];
    }
};