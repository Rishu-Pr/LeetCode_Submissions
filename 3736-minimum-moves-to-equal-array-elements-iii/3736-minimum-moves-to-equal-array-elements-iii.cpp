class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxV = nums.front();
        for(int x : nums){
            maxV = max(maxV, x);
        }

        int ans = 0;
        for(int x : nums){
            ans += (maxV - x);
        }

        return ans;
    }
};