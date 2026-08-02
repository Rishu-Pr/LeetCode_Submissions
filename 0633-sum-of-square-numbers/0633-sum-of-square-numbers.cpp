class Solution {
public:
    bool judgeSquareSum(int c) {
        // 46340

        long long s = 0;
        long long e = 46340;

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