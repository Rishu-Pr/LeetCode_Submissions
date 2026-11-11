class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int maxL = 0;
        unordered_map<int, int> map;
        
        map[0] = -1;
        for(int i = 0; i < n; i++){
            currSum += (nums[i] == 0 ? -1 : 1);
            if(!map.count(currSum)){
                map[currSum] = i;
            }
            else{
                maxL = max(maxL, i - map[currSum]);
            }
        }

        return maxL;
    }
};