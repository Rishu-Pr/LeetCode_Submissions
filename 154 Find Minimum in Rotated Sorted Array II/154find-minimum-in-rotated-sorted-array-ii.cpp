class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX,left=0,right=nums.size()-1;
        while(left<=right){
            if(nums[left]<min){
                min=nums[left];
            }
            if(nums[right]<min){
                min=nums[right];
            }
            left++;
            right--;
        }
        return min;
    }
};