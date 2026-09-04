class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            int maxV = 0;
            int minV = INT_MAX;
            for(int k = 0; k <= i; k++){
                maxV = max(maxV, nums[k]);
            }
            for(int k = i; k < nums.size(); k++){
                minV = min(minV, nums[k]);
            }

            if(maxV - minV <= k){
                return i;
            }
        }

        return -1;
    }
};