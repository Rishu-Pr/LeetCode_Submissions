class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> rem_0, rem_1, rem_2;

        for(int elem : nums){
            if(elem % 3 == 0) rem_0.push_back(elem);
            else if (elem % 3 == 1) rem_1.push_back(elem);
            else rem_2.push_back(elem);
        }

        sort(rem_0.begin(), rem_0.end());
        sort(rem_1.begin(), rem_1.end());
        sort(rem_2.begin(), rem_2.end());

        int ans = 0;
        if(rem_0.size() >= 3) ans = max(ans, rem_0[rem_0.size() - 1] + rem_0[rem_0.size() - 2] + rem_0[rem_0.size() - 3]);
        if(rem_1.size() >= 3) ans = max(ans, rem_1[rem_1.size() - 1] + rem_1[rem_1.size() - 2] + rem_1[rem_1.size() - 3]);
        if(rem_2.size() >= 3) ans = max(ans, rem_2[rem_2.size() - 1] + rem_2[rem_2.size() - 2] + rem_2[rem_2.size() - 3]);

        if(!rem_0.empty() && !rem_1.empty() && !rem_2.empty())
            ans = max(ans, rem_0.back() + rem_1.back() + rem_2.back());

        return ans; 
    }
};