class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
        int i = 1;
        int idx = 0;

        for(; idx < target.size(); i++){
            if(i != target[idx]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else{
                ans.push_back("Push");
                idx++;
            }
        }

        return ans;
    }
};