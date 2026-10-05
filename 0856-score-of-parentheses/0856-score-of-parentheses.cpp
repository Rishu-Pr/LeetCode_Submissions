class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> stk;
        int sum = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                stk.push(sum);
                sum = 0;
            }
            else{
                sum = stk.top() + max(2 * sum, 1);
                stk.pop();
            }
        }
        return sum;
    }
};