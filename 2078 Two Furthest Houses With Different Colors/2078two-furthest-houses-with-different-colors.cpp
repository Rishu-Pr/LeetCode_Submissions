class Solution {
public:
    int maxDistance(vector<int> &colors)
    {
        int distn = 0;
        int size = colors.size();
        for (int i = 0; i <= size / 2; i++)
        {
            if ((colors[i] != colors[size - 1]) && (size - i - 1 > distn))
            {
                distn = size - 1 - i;
            }
        }
        for (int i = size - 1; i >= size / 2; i--)
        {
            if ((colors[i] != colors[0]) && (i > distn))
            {
                distn = i;
            }
        }
        return distn;
    }
};