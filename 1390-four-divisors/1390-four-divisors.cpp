class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            int n = sqrt(x);
            int cnt = 0;
            int sum = 0;
            for(int i = 1; i <= n; i++){
                if(x % i == 0){
                    sum += i;
                    cnt++;
                    if (i != (x / i)) {
                        sum += (x / i);
                        cnt++;
                    }
                }
                if (cnt > 4) {
                    break;
                }
            }

            if(cnt == 4){
                ans += sum;
            }
        }

        return ans;
    }
};