class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = -1;
        int b = -1;
        int c = -1;
        int maxV = -101;

        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] > maxV){
                maxV = nums[i];
                a = i;
            }
        }
        
        maxV = -101;
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] > maxV && i != a){
                maxV = nums[i];
                b = i;
            }
        }
        
        maxV = 101;
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] < maxV && i != a && i != b){
                maxV = nums[i];
                c = i;
            }
        }
        
        return nums[a] + nums[b] - nums[c];
    }
};