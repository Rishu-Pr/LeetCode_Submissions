class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> V(26, 0);
        int maxLen = 0;

        int front = 0;
        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            int idx = x - 'a';
            V[idx]++;

            if(V[idx] > 2){
                while(V[idx] > 2){
                    V[s[front] - 'a']--;
                    front++;
                }
            }

            maxLen = max(maxLen, i - front + 1);
        }

        return maxLen;


    }
};