class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> Ans;
        Ans.push_back(envelopes[0][1]);

        for(int i = 1; i < envelopes.size(); i++){
            if(envelopes[i][1] > Ans.back())
                Ans.push_back(envelopes[i][1]);

            else{
                int idx = lower_bound(Ans.begin(), Ans.end(), envelopes[i][1]) - Ans.begin();
                Ans[idx] = envelopes[i][1];
            }
        }

        return Ans.size();
    }
};