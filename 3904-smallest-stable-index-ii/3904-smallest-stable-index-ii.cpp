class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxA(n);
        vector<int> minA(n);

        int maxV = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxV = max(maxV, nums[i]);
            maxA[i] = maxV;
        }

        int minV = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            minV = min(minV, nums[i]);
            minA[i] = minV;
        }

        for(int i = 0; i < n; i++){
            int V = maxA[i] - minA[i];
            if(V <= k){
                return i;
            }
        }

        return -1;
    }
};