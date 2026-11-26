class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int rem = 10;
        while(rem <= n){
            n -= rem;
            ans = !ans;  
            rem--;      
        }

        return ans;
    }
};