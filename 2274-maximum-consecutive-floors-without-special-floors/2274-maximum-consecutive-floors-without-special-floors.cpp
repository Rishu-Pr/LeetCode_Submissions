class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n = special.size();

        int idx = 0;
        while(idx < n && special[idx] < bottom){
            idx++;
        }
        int maxL = (idx < n) ? special[0] - bottom : 0;

        for(int i = idx; i < n - 1; i++){
            maxL = max(maxL ,special[i + 1] - special[i] - 1);
        }

        maxL = max(maxL, top - special.back());

        return maxL;
    }
};