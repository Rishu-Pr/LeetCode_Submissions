class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> Ans(n + 1, 0);
        Ans[0] = 0;
        Ans[1] = 1;
        int idx = 1;

        while(Ans.back() == 0){
            int temp_Val = Ans[idx];
            int temp_idx = idx << 1;
            Ans[temp_idx] = temp_Val;
            if(Ans.back() == 0) Ans[temp_idx + 1] = temp_Val + 1;

            idx++;
        }

        return Ans;
    }
};