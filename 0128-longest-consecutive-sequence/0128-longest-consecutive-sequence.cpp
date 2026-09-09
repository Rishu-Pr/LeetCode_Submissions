class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxL = 1;
        int temp = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] == nums[i]){
                continue;
            }
            else if(nums[i + 1] - nums[i] == 1){
                temp++;
            }
            else{
                maxL = max(maxL, temp);
                temp = 1;
            }
        }

        return max(temp, maxL);
    }
};