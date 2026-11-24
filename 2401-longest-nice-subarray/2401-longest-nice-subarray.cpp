class Solution {
    void addBit(int x, vector<int> &V){
        int idx = 0;
        while(x){
            V[idx] += (x % 2);
            idx++;
            x /= 2;
        }
    }
    void subBit(int x, vector<int> &V){
        int idx = 0;
        while(x){
            V[idx] -= (x % 2);
            idx++;
            x /= 2;
        }
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(31, 0);
        int left = 0;
        int maxV = 0;
        for(int i = 0; i < n; i++){
            addBit(nums[i], map);
            int checkIdx = 0;
            for(int j = 0; j < 31; j++){
                while(map[j] > 1){
                    subBit(nums[left], map);
                    left++;
                }
            }

            maxV = max(maxV, i - left + 1);
        }
        return maxV;
    }
};