class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        long long ans = n / 2;
        while(ans * ans > n){
            ans--;
        }

        return ans;
    }
};