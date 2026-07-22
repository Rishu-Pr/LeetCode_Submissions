class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target){
            return false;
        }
        int gcd_num = gcd(x, y);
        if(target % gcd_num == 0){
            return true;
        }

        return false;
    }
};