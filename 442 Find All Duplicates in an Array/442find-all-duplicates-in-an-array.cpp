class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> V(nums.size()+1,0);
        vector<int> Ans;
        for(int i=0;i<nums.size();i++){
            V[nums[i]] += 1; 
        }

        for(int i=1;i<=nums.size();i++){
            if(V[i]>1) Ans.push_back(i);
        }

        return Ans;
    }
};