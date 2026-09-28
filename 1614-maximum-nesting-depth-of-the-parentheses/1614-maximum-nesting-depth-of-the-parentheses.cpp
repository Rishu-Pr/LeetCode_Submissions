class Solution {
public:
    int maxDepth(string s) {
        // stack<char> stk;
        int cnt = 0;
        int maxV = 0;
        for(char c : s){
            if(c == '('){
                cnt++;
            }
            else if(c == ')'){
                cnt--;
            }

            maxV = max(maxV, cnt);
        }

        return maxV;
    }
};