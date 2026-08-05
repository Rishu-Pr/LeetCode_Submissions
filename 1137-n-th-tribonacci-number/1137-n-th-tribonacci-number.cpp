class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n <= 2){
            return 1;
        }
        int x = 0, y = 1, z = 1, res;
        while(n - 2){
            res = x + y + z;
            x = y;
            y = z;
            z = res;

            n--;
        }

        return res;
    }
};