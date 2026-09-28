class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> V;
        int d = 0;
        
        for (char c : seq) {
            if (c == '(') {
                d++;
                V.push_back(d % 2);
            } 
            else {
                V.push_back(d % 2);
                d--;
            }
        }

        return V;
    }
};