class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> Ans;
        if(m * n !=  original.size()) return Ans;

        for(int i = 0; i < m; i++){
            vector<int> subset(original.begin() + i*n,original.begin()+(i+1)*n);
            Ans.push_back(subset);
        }

        return Ans;
    }
};