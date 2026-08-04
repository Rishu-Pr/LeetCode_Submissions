class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> Ans;
        int beg = nums[0];
        int end = nums.back();
        int idx = 0;
        while(beg < end && idx < nums.size()){
            if(nums[idx] == beg){
                idx++;
            }
            else{
                Ans.push_back(beg);
            }
            beg++;
        }

        return Ans;
    }
};