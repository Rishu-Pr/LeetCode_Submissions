class Solution {
    int getPow(int base,int power){
        int ans = 1;
        for(int i = 0 ;i<power ;i++){
            ans %= 1337;
            ans *= (base % 1337);
        }
        return (ans % 1337);
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        int a_mod = a % 1337;
        for(int i=0 ; i < b.size(); i++){
            ans %= 1337;
            ans = getPow(ans,10);
            ans %= 1337;
            ans *= getPow(a_mod,b[i]);
        }

        return ans % 1337;
    }
};