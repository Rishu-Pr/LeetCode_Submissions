class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = INT_MAX;
        int max = -1;
        for(int x: nums){
            if(x < min){
                min = x;
            }
            else if((x-min>max) && (x-min!=0)){
                max = x-min;
            }
        }
        return max;
    }
};