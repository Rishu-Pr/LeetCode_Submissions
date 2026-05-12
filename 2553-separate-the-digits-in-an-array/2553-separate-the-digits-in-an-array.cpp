class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int x : nums){
            int n = ans.size();
            while(x > 0){
                ans.push_back(x % 10);
                x /= 10;
            }
            reverse(ans.begin() + n, ans.end());
        }
        return ans;
    }
};