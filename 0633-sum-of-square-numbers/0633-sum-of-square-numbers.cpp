class Solution {
public:
    bool judgeSquareSum(int c) {
        // 46340

        int s = 0;
        long long e = sqrt(c);

        while(s <= e){
            if(s * s + e * e > c){
                e--;
            }
            else if(s * s + e * e < c){
                s++;
            }
            else{
                return true;
            }
        }

        return false;
    }
};