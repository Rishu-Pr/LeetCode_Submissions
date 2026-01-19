class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT32_MAX;
        int max = 0;
        for (int num : prices)
        {
            if (num < min)
            {
                min = num;
            }
            else if (num - min > max)
            {
                max = num - min;
            }
        }

        return max;
    }
};