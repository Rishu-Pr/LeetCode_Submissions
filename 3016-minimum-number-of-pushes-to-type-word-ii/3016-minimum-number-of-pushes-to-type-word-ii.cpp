class Solution {
public:
    int minimumPushes(string word) {
        vector<int> V(26, 0);
        for(char c : word){
            V[c - 'a']++;
        }
        sort(V.begin(), V.end());

        int cnt = 0;
        int multiplier = 1;
        int v = 0;
        for(int i = 25; i >= 0; i--){
            if(V[i] != 0){
                cnt += (V[i] * multiplier);
                v++;
                if(v == 8){
                    multiplier++;
                    v = 0;
                }
            }
        }

        return cnt;
    }
};