class Solution {
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> V;
        for (int i = 0; i < nums.size();){
            int count = 1;
            while (i + count < nums.size() && nums[i] == nums[i + count])
                count++;

            if (count > nums.size() / 3)
                V.push_back(nums[i]);
            i += count;
        }
        return V;
    }
};