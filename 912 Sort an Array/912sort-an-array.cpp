class Solution {
    int getMax(vector<int>& nums){
        int maxVal = nums[0];
        for(int i = 1; i<nums.size(); i++)
            maxVal = max(maxVal,nums[i]);

        return maxVal;
    }

    void countSort(vector<int>& nums, int exp){
        vector<vector<int>> V(10);
        int t = 0;

        for(int i = 0; i < nums.size(); i++)
            V[(nums[i]/exp) % 10].push_back(nums[i]);

        for(int i = 0; i < V.size(); i++)
            for(int j = 0; j < V[i].size(); j++)
                nums[t++] = V[i][j];
    }

public:
    vector<int> sortArray(vector<int>& nums) {

        vector<int> posit,neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) neg.push_back(nums[i]*-1);
            else posit.push_back(nums[i]);
        }

        if(!posit.empty()){
            int maxPos = getMax(posit);
            for (int exp = 1; maxPos/exp > 0; exp *= 10)
                countSort(posit, exp);
        }

        if(!neg.empty()){
            int maxPos = getMax(neg);
            for (int exp = 1; maxPos/exp > 0; exp *= 10)
                countSort(neg, exp);
            reverse(neg.begin(), neg.end());
            for (int &x : neg) x = -x;
        }

        int t = 0;
        for(int i = 0; i < neg.size(); i++) nums[t++] = neg[i];
        for(int i = 0; i < posit.size(); i++) nums[t++] = posit[i];

        return nums;
    }
};