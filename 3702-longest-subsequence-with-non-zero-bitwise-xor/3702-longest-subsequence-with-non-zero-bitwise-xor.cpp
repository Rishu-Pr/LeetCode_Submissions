class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int non_zero = 0;
        int zero = 0;
        int ans = 0;

        for(int x : nums){
            if(x == 0){
                zero++;
            }
            else{
                non_zero++;
                ans ^= x;
            }
        }

        if(zero == nums.size()){
            return 0;
        }
        else if(ans == 0){
            return zero + non_zero - 1;
        }

        return zero + non_zero;
    }
};