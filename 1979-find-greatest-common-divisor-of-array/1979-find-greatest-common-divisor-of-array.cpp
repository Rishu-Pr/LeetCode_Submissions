class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minV = 1e5;
        int maxV = -1;

        for(int i = 0; i < nums.size(); i++){
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }

        return gcd(minV, maxV);
    }
};