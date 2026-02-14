class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> V_Ans;
        if(nums.size()<3) return V_Ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++){

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < nums.size() - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = nums.size() - 1;

                while (left < right){
                    long long int sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];
                    if (sum == target)
                    {
                        V_Ans.push_back({nums[left++], nums[i], nums[j], nums[right--]});
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                    }

                    else if (sum > target)
                        right--;

                    else
                        left++;
                }
            }
        }
        return V_Ans;
    }
};