class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> V(24, 0);
        for(int x : candidates){
            int idx = 0;
            while(idx < 24){
                V[idx] += x % 2;
                x /= 2;
                idx++;
            }
        }

        int maxV = 0;
        for(int x : V){
            maxV = max(maxV, x);
        }

        return maxV;
    }
};