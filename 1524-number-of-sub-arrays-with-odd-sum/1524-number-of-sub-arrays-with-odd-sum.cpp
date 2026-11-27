class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        
        int prefixParity = 0;
        long long cntOdd = 0;
        long long cntEven = 0;
        
        for (int x : arr) {
            prefixParity = (prefixParity + x) % 2;
            if (prefixParity == 1) {
                cntOdd++;
            } else {
                cntEven++;
            }
        }

        long long ttl = (1LL * n * (n + 1)) / 2;
        long long evenCnt = (cntEven * (cntEven + 1)) / 2;
        long long oddCnt = (cntOdd * (cntOdd - 1)) / 2;
        
        return (ttl - evenCnt - oddCnt) % MOD;
    }
};