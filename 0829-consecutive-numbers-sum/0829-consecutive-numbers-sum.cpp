class Solution {
public:
    int consecutiveNumbersSum(int n) {
        long long ans = 0;
        long long k = 44722;

        for(int i = 1; i * (i - 1) / 2 < n; i++){
            if((n - i * (i - 1) / 2) % i == 0){
                ans++;
            }
        }

        return ans;
    }
};