class Solution {
public:
    int minStartValue(vector<int> &nums)
    {
        int max = 1;
        int sum = 0;
        for (int x : nums)
        {
            int val = sum + max + x;
            if (val < 1)
            {
                max += (1 - val);
            }
            sum += x;
        }
        return max;
    }
};