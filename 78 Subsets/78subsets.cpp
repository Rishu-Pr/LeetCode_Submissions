class Solution {
    void subsetGen(int idx,vector<int>& nums,vector<int> &temp,vector<vector<int>>& V){
        if(idx >= nums.size()){
            V.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsetGen(idx+1,nums,temp,V);

        temp.pop_back();
        subsetGen(idx+1,nums,temp,V);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> V;
        vector<int> temp;
        subsetGen(0,nums,temp,V);
        return V;
    }
};