class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> V;
        for(int i = 0; i < words.size(); i++){
            int val = 0;
            for(char c : words[i]){
                val |= 1 << (c - 'a');
            }
            V.push_back(val);
        }

        int ans = 0;
        for(int i = 0; i < V.size(); i++){
            for(int j = i + 1; j < V.size(); j++){
                if((V[i] & V[j]) == 0){
                    int temp = words[i].size() * words[j].size();
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};