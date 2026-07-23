class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size() == 1){
            return to_string(nums[0]); 
        }
        string ans = "";
        ans += to_string(nums.front());
        ans += "/(";
        if(nums.size() == 2){
            ans.pop_back();
            ans += to_string(nums[1]);
            return ans;
        }

        for(int i = 1; i < nums.size(); i++){
            ans += to_string(nums[i]);
            ans += "/";
        }
        ans.pop_back();
        ans += ")";

        return ans;
    }
};