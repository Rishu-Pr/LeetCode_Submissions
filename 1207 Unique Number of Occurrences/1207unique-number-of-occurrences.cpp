class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> H1;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i] == arr[1 + i])
            {
                cnt++;
                i++;
            }
            H1.push_back(cnt);
        }

        sort(H1.begin(), H1.end());
        for (int i = 1; i < H1.size(); i++)
        {
            if (H1[i] == H1[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};