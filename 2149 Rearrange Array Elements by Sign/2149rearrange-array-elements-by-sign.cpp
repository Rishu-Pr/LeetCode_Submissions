class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> V(nums.size(), 0);
        int even_idx = 0, odd_idx = 1;
        for (int x : nums)
        {
            if (x > 0)
            {
                V[even_idx] = x;
                even_idx += 2;
            }
            else
            {
                V[odd_idx] = x;
                odd_idx += 2;
            }
        }
        return V;
    }
};