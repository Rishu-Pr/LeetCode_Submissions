class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int isLonely = 0;
            if(i > 0 && nums[i - 1] >= nums[i] - 1){
                isLonely++;
            }
            if(i < n - 1 && nums[i] >= nums[i + 1] - 1){
                isLonely++;
            }

            if(isLonely == 0){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};