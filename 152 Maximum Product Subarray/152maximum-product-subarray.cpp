class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int ans=nums[0];
        int cur_Max=nums[0];
        int cur_Min=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(cur_Max,cur_Min);
            
            cur_Max=max(nums[i],cur_Max*nums[i]);
            cur_Min=min(nums[i],cur_Min*nums[i]);

            ans = max(cur_Max,ans);
        }

        return ans;
    }
};