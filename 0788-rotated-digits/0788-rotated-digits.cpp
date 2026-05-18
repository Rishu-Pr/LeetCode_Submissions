class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            int num = i;
            
            bool is_valid = true;
            bool is_changeable = false;
            
            while(num > 0){
                int digit = num % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    is_valid = false;
                    break;
                }

                if(digit == 2 || digit == 5 || digit == 6 ||digit == 9)
                    is_changeable = true;

                num /= 10;
            }

            if(is_changeable && is_valid) count++;
        }

        return count;
    }
};