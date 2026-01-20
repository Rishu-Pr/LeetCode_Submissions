class Solution {
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int size = arr.size();
        for (int i = 0; i < size-1; i++)
        {
            int maxVal = arr[i + 1];
            for (int j = i + 2; j < size; j++) // [17,18,5,4,6,1]
            {
                if (arr[j] > maxVal)
                {
                    maxVal = arr[j];
                }
            }
            arr[i] = maxVal;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};