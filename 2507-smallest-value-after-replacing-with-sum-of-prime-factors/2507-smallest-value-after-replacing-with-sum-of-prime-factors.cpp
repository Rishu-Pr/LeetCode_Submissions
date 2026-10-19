class Solution {
    int primeFact(int n){
        int sum = 0;
        while(n % 2 == 0){
            sum += 2;
            n /= 2;
        }
        for(int i = 3; i <= sqrt(n); i += 2){
            while(n % i == 0){
                sum += i;
                n /= i;
            }
        }
        if(n > 2){
            sum += n;
        }

        return sum;
    }
public:
    int smallestValue(int n) {
        int minV = n;
        while(primeFact(n) != n && primeFact(n) < n){
            n = primeFact(n);
        }

        return n;
    }
};