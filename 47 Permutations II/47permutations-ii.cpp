class Solution {
public:

    void getperms(vector<int> &V, vector<vector<int>> &ans, int idx)
    {
        if (idx == V.size())
        {
            ans.push_back(V);
            return;
        }
        unordered_set<int> used;
        for (int i = idx; i < V.size(); i++)
        {
            if (used.count(V[i]))
                continue;

            used.insert(V[i]);
            swap(V[idx], V[i]);
            getperms(V, ans, idx + 1);
            swap(V[idx], V[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getperms(nums, ans, 0);
        
        return ans;
    }
};