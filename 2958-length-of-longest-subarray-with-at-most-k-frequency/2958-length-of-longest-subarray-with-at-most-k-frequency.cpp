class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxVal = 0;
        unordered_map<int, int> map;

        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;

            while(map[nums[i]] > k){
                map[nums[left]]--;
                left++;
            }

            maxVal = max(maxVal, i - left + 1);
        }

        return maxVal;
    }
};