class Solution {
    bool check(vector<int>& a,vector<int>& b){
        if(b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for(int c = n - 1; c >= 0; c--){
            for(int p = c - 1; p >= -1; p--){
                int take = 0;
                if(p == -1 || check(cuboids[c], cuboids[p]))
                    take = cuboids[c][2] + next[c + 1];
                int notTake = next[p + 1];

                curr[p + 1] = max(take, notTake);
            }
            next = curr;
        }

        return next[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i = 0; i < cuboids.size(); i++)
            sort(cuboids[i].begin(), cuboids[i].end());
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids);
    }
};