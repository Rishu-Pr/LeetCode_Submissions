class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool ifZ = false;
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                ifZ = true;
            }
        }
        if(!ifZ){
            return nums.size() - 1;
        }
        int lenA = 0;
        int lenB = 0;
        int temp = 0;

        int ans = 0;
        for(int x : nums){
            if(x){
                temp++;
            }
            else{
                lenA = lenB;
                lenB = temp;
                ans = max(ans, lenA + lenB);
                temp = 0;
            }
        }
        ans = max(ans, lenB + temp);
        return ans;
    }
};