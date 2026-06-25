class Solution {
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int count = 0;
        int i = 0;
        while (i < nums.size())
        {
            int target_num = 0;
            int non_target_num = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] == target) target_num++;
                else non_target_num++;

                if (target_num > non_target_num) count++;
            }
            i++;
        }
        return count;
    }
};