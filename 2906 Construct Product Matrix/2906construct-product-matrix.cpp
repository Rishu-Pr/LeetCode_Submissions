class Solution
{
    int mod = 12345;

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int size = grid.size() * grid[0].size();
        int arr[size];
        int t = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                arr[t++] = grid[i][j];

        vector<int> prefix(size,1);
        vector<int> suffix(size,1);

        for(int i = 1; i< size;i++)
            prefix[i] = (prefix[i-1]*(arr[i-1]%mod)) % mod;
        
        for(int i = size-2; i>=0;i--)
            suffix[i] = (suffix[i+1]*(arr[i+1]%mod)) % mod;

        t=0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                grid[i][j] = (prefix[t]*suffix[t++]) % mod;

        return grid;
    }
};