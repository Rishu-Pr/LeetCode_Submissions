class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){

            for(int j = i; j >= 0; j--){
                int inc = satisfaction[i] * (j + 1) + prev[j + 1];
                int exc = prev[j];
                curr[j] = max(inc, exc);
            }

            prev = curr;
        }

        return prev[0];
    }
};