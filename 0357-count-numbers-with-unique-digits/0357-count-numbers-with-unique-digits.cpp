class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        int count = 10;

        int unique_digit = 9;
        int unique_num = 9;

        for(int i = 2; i <= n; i++){
            unique_num *= unique_digit;
            count += unique_num;

            unique_digit--;
        }

        return count;
    }
};