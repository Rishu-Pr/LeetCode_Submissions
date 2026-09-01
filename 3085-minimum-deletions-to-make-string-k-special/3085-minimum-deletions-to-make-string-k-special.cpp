class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }
        int minV = INT_MAX;
        for(int i : freq){
            if(i != 0){
                int v = 0;
                for(int j = 0; j < freq.size(); j++){
                    if(freq[j] < i){
                        v += freq[j];
                    }
                    else if(freq[j] > i + k){
                        v += freq[j] - i - k;
                    }
                }
                minV = min(minV, v);
            }
        }

        return minV;
    }
};