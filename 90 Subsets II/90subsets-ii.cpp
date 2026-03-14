class Solution {
public:
    void subsets(int idx, vector<int> &nums, vector<vector<int>> &V_Ans, vector<int> &temp)
    {
        if (idx >= nums.size())
        {
            V_Ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsets(idx + 1, nums, V_Ans, temp);
        temp.pop_back();

        subsets(idx + 1, nums, V_Ans, temp);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> V_Ans;
        vector<vector<int>> V_Ans_Unique;
        vector<int> temp;
        subsets(0, nums, V_Ans, temp);


        sort(V_Ans.begin(), V_Ans.end());
        V_Ans_Unique.push_back(V_Ans[0]);
        for (int i = 0; i < V_Ans.size(); i++)
            sort(V_Ans[i].begin(), V_Ans[i].end());

        sort(V_Ans.begin(), V_Ans.end());
        for (int i = 1; i < V_Ans.size();)
        {
            if (V_Ans[i] != V_Ans[i - 1]) V_Ans_Unique.push_back(V_Ans[i]);
            i++;
        }

        return V_Ans_Unique;
    }
};