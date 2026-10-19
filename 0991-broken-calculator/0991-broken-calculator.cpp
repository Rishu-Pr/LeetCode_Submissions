class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while(startValue != target){
            if(target > startValue){
                if(target % 2){
                    target++;
                }
                else{
                    target /= 2;
                }
                cnt++;
            }
            else{
                cnt += startValue - target;
                break;
            }
        }
        return cnt;
    }
};