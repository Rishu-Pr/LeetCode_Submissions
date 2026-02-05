class Solution
{

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size = nums1.size() + nums2.size();
        vector<int> V_Ans;
        V_Ans.insert(V_Ans.begin(), nums1.begin(), nums1.end());
        V_Ans.insert(V_Ans.end(), nums2.begin(), nums2.end());

        sort(V_Ans.begin(), V_Ans.end());

        if (size % 2 == 0)
            return (V_Ans[size / 2 - 1] + V_Ans[size / 2]) / 2.0;

        else
            return V_Ans[size / 2];
    }
};