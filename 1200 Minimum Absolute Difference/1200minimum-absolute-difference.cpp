class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> V_ans;
        sort(arr.begin(), arr.end());
        int min_Dif = INT32_MAX;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] - arr[i] < min_Dif)
            {
                min_Dif = arr[i + 1] - arr[i];
            }
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            vector<int> V;
            if (arr[i + 1] - arr[i] == min_Dif)
            {
                V.push_back(arr[i]);
                V.push_back(arr[i + 1]);
                V_ans.push_back(V);
            }
        }
        return V_ans;
    }
};