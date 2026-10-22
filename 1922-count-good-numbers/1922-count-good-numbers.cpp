class Solution {
    long long solve(long long base, long long pwr){
        int MOD = 1e9 + 7;
        int res = 1;
        while(pwr > 0){
            if(pwr & 1){
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            pwr >>= 1;
        }
        return res % MOD;
    }
public:
    int countGoodNumbers(long long n) {
        int MOD = 1e9 + 7;
        long long cnt = 1;

        long long p = n / 2;
        long long e = n - p;

        cnt = (cnt * solve(5, e)) % MOD;
        cnt = (cnt * solve(4, p)) % MOD;

        return cnt;
    }
};