class Solution
{
    vector<vector<int>> idx_sequence;
    void Sort(vector<string> &nums, vector<int> &indices, int i)
    {
        vector<vector<int>> index_collection(10);
        int n = nums[0].size();

        for (int idx : indices)
            index_collection[nums[idx][n - 1 - i] - '0'].push_back(idx);

        int t = 0;
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < index_collection[j].size(); k++)
                indices[t++] = index_collection[j][k];
        }

        idx_sequence.push_back(indices);
    }

    void radixSort(vector<string> &nums)
    {
        vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); i++)
            indices[i] = i;

        for (int i = 0; i < nums[0].size(); i++)
            Sort(nums, indices, i);
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> Ans;
        radixSort(nums);

        for (int i = 0; i < queries.size(); i++)
            Ans.push_back(idx_sequence[queries[i][1] - 1][queries[i][0] - 1]);

        return Ans;
    }
};

