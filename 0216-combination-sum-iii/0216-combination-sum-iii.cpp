class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& temp, int k, int n, int last_elem){
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(k <= 0 || n <= 0){
            return;
        }

        for(int i = last_elem + 1; i <= n / k && i < 10; i++){
            temp.push_back(i);
            solve(ans, temp, k - 1, n - i, i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n <= k){
            return ans;
        }
        vector<int> temp;
        solve(ans, temp, k, n, 0);
        return ans;
    }
};