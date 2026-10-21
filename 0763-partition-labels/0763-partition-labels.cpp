class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> V(26, 0);
        for(int i = 0; i < n; i++){
            char c = s[i];
            V[c - 'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for(int i = 0; i < n; i++){
            char c = s[i];
            end = max(end, V[c - 'a']);
            if(i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};