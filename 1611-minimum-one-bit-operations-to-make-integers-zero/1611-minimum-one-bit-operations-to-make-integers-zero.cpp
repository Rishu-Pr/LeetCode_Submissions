class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int cnt = 1;
        int sign = 1;
        while(n > 0){
            if(n % 2){
                ans += (pow(2, cnt) - 1) * sign;
                sign *= -1;
            }
            n /= 2;
            cnt++;
        }

        return abs(ans);
    }
};