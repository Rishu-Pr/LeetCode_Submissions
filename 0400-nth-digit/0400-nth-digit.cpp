class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10){
            return n;
        }
        vector<long long> nines = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999};
        vector<long long> V = {9};
        long long idx = 9;
        int t = 2;
        for(int i = 0; i < 9; i++){
            idx *= 10;
            V.push_back(idx * t);
            t++;
        }

        idx = 0;
        t = 1;

        while(n > V[idx]){
            n -= V[idx];
            idx++;
            t++;
        }

        int div = n / t;
        int mod = n % t;
        
        div += nines[t - 2];

        if(mod){
            div++;
        }
        vector<int> nums;
        while(div > 0){
            nums.push_back(div % 10);
            div /= 10;
        }
        if(mod == 0){
            return nums[0];
        }
        reverse(nums.begin(), nums.end());
        return nums[mod - 1];
    }
};