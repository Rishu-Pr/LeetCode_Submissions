class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxA(n);
        vector<int> minA(n);

        int maxV = INT_MIN;
        int minV = INT_MAX;
        for(int i = 0; i < n; i++) {
            maxV = max(maxV, nums[i]);
            minV = min(minV, nums[n - 1 - i]);
            maxA[i] = maxV;
            minA[n - 1 - i] = minV;
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