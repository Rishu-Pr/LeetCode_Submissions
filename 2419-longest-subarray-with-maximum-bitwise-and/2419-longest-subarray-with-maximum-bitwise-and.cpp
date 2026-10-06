class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxV = nums[0];
        int maxL = 1;

        int idx = 1;
        while(idx < nums.size()){
            if(nums[idx] == maxV && nums[idx] == nums[idx - 1]){
                int tlen = 1;
                while(idx < nums.size() && nums[idx] == maxV){
                    tlen++;
                    idx++;
                }
                maxL = max(maxL, tlen);
            }
            else if(nums[idx] > maxV){
                maxV = nums[idx];
                maxL = 1;
                idx++;
            }
            else{
                idx++;
            }
        }

        return maxL;
    }
};