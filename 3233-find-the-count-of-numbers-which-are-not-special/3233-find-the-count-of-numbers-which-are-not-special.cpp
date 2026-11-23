class Solution {
    void countP(int l, int r, vector<int>& V){
        int n = r;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= n; i++){
            if(isPrime[i] && i * i <= n){
                for(int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        // int c = 0;
        for(int i = l; i <= r; i++){
            if(isPrime[i]){
                // c++;
                V.push_back(i);
            }
        }

        // return c;
    }
public:
    int nonSpecialCount(int l, int r) {
        int rtl = pow(l, 0.5);
        int rtr = pow(r, 0.5);

        vector<int> V;
        countP(rtl, rtr, V);
        int c = 0;
        for(int x : V){
            int res = x * x;
            if(res >= l && res <= r){
                c++;
            }
        }

        return r - l + 1 - c;
    }
};