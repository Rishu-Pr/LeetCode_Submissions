class Solution {
    void valF(int n, vector<int>& ans){
        int x = sqrt(n);
        while(x){
            int y = n / x;
            if(x * y == n){
                if(abs(x - y) < abs(ans[0] - ans[1])){
                    ans[0] = x;
                    ans[1] = y;
                    break;
                }
            }
            x--;
        }
    }
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans = {0, 1000000000};
        valF(num + 1, ans);
        valF(num + 2, ans);

        return ans;
    }
};