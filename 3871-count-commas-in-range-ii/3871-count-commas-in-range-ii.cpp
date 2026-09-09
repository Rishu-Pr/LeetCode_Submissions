class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long maxV = 1000000000000000;
        vector<long long> dta = {999, 999999, 999999999, 999999999999};

        if(n > dta[0]){
            ans += n - dta[0];
        }
        if(n > dta[1]){
            ans += n - dta[1];
        }
        if(n > dta[2]){
            ans += n - dta[2];
        }
        if(n > dta[3]){
            ans += n - dta[3];
        }
        if(n == maxV){
            ans++;
        }
        return ans;
    }
};