class Solution {
    int solve(int num){
        int sum = 0;
        while(num){
            sum += (num % 10);
            num /= 10;
        }

        return (sum >= 10) ? solve(sum) : sum;
    }
public:
    int addDigits(int num) {
        return solve(num);
    }
};