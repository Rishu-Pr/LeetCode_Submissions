class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        vector<int> ans(n, 0);
        sort(satisfaction.begin(), satisfaction.end());

        for(int i = 0; i < n; i++){
            int idx = 1;
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += satisfaction[j] * idx;
                idx++;
            }
            ans[i] = sum;
        }
        sort(ans.begin(), ans.end());
        
        return (ans.back() <= 0) ? 0 : ans.back();
    }
};