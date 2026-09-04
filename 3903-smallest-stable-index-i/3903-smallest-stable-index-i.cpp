class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxA(n);
        vector<int> minA(n);
        maxA[0] = nums[0];
        minA[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            maxA[i] = max(maxA[i - 1], nums[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            minA[i] = min(minA[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++){
            if(maxA[i] - minA[i] <= k){
                return i;
            }
        }
        return -1;
    }
};