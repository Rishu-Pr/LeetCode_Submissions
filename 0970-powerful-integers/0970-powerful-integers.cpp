class Solution {
public:
    long long power(long long b, long long e){
        long long res = 1;
        while(e){
            if(e % 2){
                res *= b;
            }
            b *= b;
            e /= 2;
        }
        return res;
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x == 1 && y == 1){
            if(bound >= 2){
                return {2};
            }
            return {};
        }

        vector<int> ans;
        if(x == 1 || y == 1){
            int num = x + y - 1;
            int pwr = 0;
            while(power(num, pwr) + 1 <= bound){
                ans.push_back(power(num, pwr) + 1);
                pwr++;
            }
            return ans;
        }

        set<int> unique;
        int pwrx = 0;
        while(power(x,pwrx) <= bound){
            int pwry = 0;
            int sum = power(x, pwrx) + power(y, pwry);
            while(sum <= bound){
                unique.insert(sum);
                pwry++;
                sum = power(x, pwrx) + power(y, pwry);
            }
            pwrx++;
        }

        for(int x : unique){
            ans.push_back(x);
        }

        return ans;
    }
};