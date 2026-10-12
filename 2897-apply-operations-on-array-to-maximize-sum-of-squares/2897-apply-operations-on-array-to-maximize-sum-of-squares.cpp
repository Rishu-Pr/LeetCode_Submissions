class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        vector<int> V(31, 0);
        for(int x : nums){
            int idx = 0;
            while(x){
                if(x % 2){
                    V[idx]++;
                }
                idx++;
                x /= 2;
            }
        }

        long long ans = 0;
        while(k){
            long long x = 0;
            for(int i = 0; i < 31; i++){
                if(V[i] > 0){
                    x += pow(2, i);
                    V[i]--;
                }
            }
            ans = (ans + (x * x) % MOD) % MOD;
            k--;
        }

        return ans;
    }
};