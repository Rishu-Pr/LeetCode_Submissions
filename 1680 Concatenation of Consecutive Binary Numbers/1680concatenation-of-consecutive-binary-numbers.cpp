class Solution {
    const int MOD = 1e9+7;
public:
    int concatenatedBinary(int n)
    {
        long s = 0;
        int step = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0) step++;
            s = ((s << step)|i)%MOD;
        }
        return s;
    }
};