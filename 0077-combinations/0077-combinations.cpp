class Solution {
    void solve(vector<int>& temp, vector<vector<int>>& ans,int idx, int k, int n){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == n){
            return;
        }

        for(int i = idx; i < n; i++){
            temp.push_back(i + 1);
            solve(temp, ans, i + 1, k - 1, n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp, ans, 0, k, n);
        return ans;
    }
};