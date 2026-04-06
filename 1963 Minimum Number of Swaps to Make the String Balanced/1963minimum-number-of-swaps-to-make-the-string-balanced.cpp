class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        for(char c : s){
            if(stk.empty() || c == '[') stk.push(c);
            else{
                if (stk.top() == '[') stk.pop();
                else stk.push(c);
            }
        }
        int cnt = 0;

        while(!stk.empty()){
            cnt++;
            stk.pop();
        }
        cnt /= 2;

        return (cnt+1)/2;
    }
};