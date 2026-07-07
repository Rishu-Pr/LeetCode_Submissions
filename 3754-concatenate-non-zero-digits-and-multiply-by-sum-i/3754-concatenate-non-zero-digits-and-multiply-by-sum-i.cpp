class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        int ctr = 0;
        while(n > 0){
            if(n % 10){
                int digit = n % 10;
                sum += digit;
                x += digit * (int)pow(10, ctr++);
            } 
            n /= 10;
        }

        return (long long)(sum * x);
    }
};