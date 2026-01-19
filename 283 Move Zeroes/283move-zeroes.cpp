class Solution {
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size();
        for (int Num : nums)
        {
            if (Num != 0)
            {
                nums[i++] = Num;
            }
        }
        while (i < j)
        {
            nums[i++] = 0;
        }
    }
};