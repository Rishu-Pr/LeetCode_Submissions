class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stk;
        vector<int> Ans(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--){
            if (stk.empty()) Ans[i] = 0;

            else if (temperatures[i] >= temperatures[stk.top()]){
                while (!stk.empty() && temperatures[i] >= temperatures[stk.top()])
                    stk.pop();

                Ans[i] = stk.empty() ? 0 : stk.top() - i;
            }
            else Ans[i] = 1;
            stk.push(i);
        }

        return Ans;
    }
};