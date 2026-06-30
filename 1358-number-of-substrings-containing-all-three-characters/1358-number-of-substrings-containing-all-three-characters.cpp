class Solution {
public:
    int numberOfSubstrings(string s) {
        int idx_A = -1, idx_B = -1, idx_C = -1;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a') idx_A = i;
            else if(s[i] == 'b') idx_B = i;
            else idx_C = i;

            count += (min(idx_A, min(idx_B, idx_C)) + 1);
        }

        return count;
    }
};