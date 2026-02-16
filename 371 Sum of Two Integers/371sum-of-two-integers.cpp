class Solution {
public:
    int getSum(int a, int b) {
        int isneg = 0;
        if (a < 0){
            a = -a;
            isneg = 1;
        }
        if (isneg) {
            for (int i = a; i > 0; i--){
                b--;
            }
        }

        else{
            for (int i = a; i > 0; i--){
                b++;
            }
        }
        
        return b;
    }
};