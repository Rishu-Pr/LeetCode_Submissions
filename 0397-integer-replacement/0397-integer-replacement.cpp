class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int oprn = 0;
        while(num > 1){
            if(!(num % 2)) num = num >> 1;
            else if(num == 3 || (num % 4) == 1) num--;
            else num++;

            oprn++;
        }

        return oprn;
    }
};