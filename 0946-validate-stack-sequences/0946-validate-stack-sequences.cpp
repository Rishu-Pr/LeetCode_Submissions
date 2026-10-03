class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = popped.size();
        vector<int> stk;
        int i1 = 0;
        int i2 = 0;

        while(i2 != popped.size()){
            while(i1 < n && pushed[i1] != popped[i2]){
                stk.push_back(pushed[i1]); i1++;
            }
            if(i1 < n){
                i1++; i2++;
            }
            while(!stk.empty() && i2 < n && stk.back() == popped[i2]){
                stk.pop_back();
                i2++;
            }
            if(i1 == n && (stk.empty() || stk.back() != popped[i2])){
                return stk.empty() && i2 == n;
            }
        }

        return true;
    }
};