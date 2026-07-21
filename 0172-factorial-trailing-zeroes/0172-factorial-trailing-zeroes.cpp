class Solution {
public:
    int trailingZeroes(int n) {
        int count_5 = 0;
        while(n > 4){
            int num = n;
            while(num % 5 == 0){
                count_5++;
                num /= 5;
            }
            n--;
        }

        return count_5;
    }
};