class Solution {
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> V;
        int sum = 0;
        for (int i = 0; i < nums.size();)
        {
            if (i == nums.size() - 1)
            {
                V.push_back(nums[i]);
                break;
            }
            else
            {
                sum = nums[i] ^ nums[i + 1];
                if (sum == 0)
                    i += 2;
                else
                {
                    V.push_back(nums[i]);
                    i++;
                }
            }
        }
        return V;
    }
};